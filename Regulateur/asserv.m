clear all;
close all;
clc;

s = tf('s');

%% Définition du procédé
te = 195e-6;
tm = 3.24e-3;
K = 479*2*pi()/60; %rad.s-1
G = K/(s*(1+te*s)*(1+tm*s));

%% Définition des paramètres
wu = 10/tm;
ti = 10/wu;
Tf = 1/(10*wu);
I = (1+ti*s)/(ti*s);
F = 1/(1+Tf*s);
[GAIN_IFU, PHASE_IFU] = bode(G*I*F, wu);
MF = 75;
PhiM = (MF - 180 - PHASE_IFU)/2;
a = (1+sin(PhiM*pi()/180))/(1-sin(PhiM*pi()/180));
ta = sqrt(a)/wu;
tb = 1/(sqrt(a)*wu);

D = ((1+(sqrt(a)/wu)*s)/(1+(1/(sqrt(a)*wu))*s));
[GAIN_DDU, PHASE_DDU] = bode(D*D, wu);

P = 1/(GAIN_IFU*GAIN_DDU);


%% Définition du Correcteur
C = P*D*D*I*F;
figure();
bode(I);
figure();
bode(D*D);
figure();
bode(F);
figure();
bode(C);

%% Affichage FTBO
figure();
margin(G*C);
figure();
bode(C*G/(1+C*G));

figure();
step(G);

figure();
step(C*G/(1+C*G));
figure();
nyquist(C*G);
figure();
nichols(C*G);

%% Transformée en z du régulateur
Tech = 0.00020358;
TZ = c2d(C, Tech, 'Method', 'zoh');
REGULATEUR = tf(TZ.Numerator{1,1}, TZ.Denominator{1,1}, Tech, 'variable', 'z^-1')
fileID = fopen('REGU_CST.hpp', 'w');
MAXORDER = max(length(REGULATEUR.Numerator{1,1}), length(REGULATEUR.Denominator{1,1}));
fprintf(fileID, '#define TAILLE_TABLEAUX %d\n', MAXORDER);
format = '%f';
for i = 2 : MAXORDER
    format = strcat(format, ',%f ');
end
fprintf(fileID, strcat('#define XCOEFFS { ', format, '}\n'), REGULATEUR.Numerator{1,1});
fprintf(fileID, strcat('#define YCOEFFS { ', format, '}\n'), REGULATEUR.Denominator{1,1});
fclose(fileID);
%zsysy = zpk(REGULATEUR)
%zplane(zsysy.Z{1,1}, zsysy.P{1,1})