%clear all;
close all;
clc;

s = tf('s');
%% Def procédé test
J = 35.9e-7;
f = 0.001109;
K = 0.0199;
R = 0.358;
L = 0.7e-3;
s = tf('s');
%%P_motor = K/(s*((J*s+f)*(L*s+R)+K^2));


%% Définition du procédé
fe = 5000;
te = 195e-6;
tm = 3.24e-3;
Reduc = 2.1428;
ecart_roue = 285;
Kreduc = 1/5.8;
Kroue = 94.24*2.1428; %mm.tr^-1
Vmax = 18;
Smax = 250;
wu = (1/(3*tm))*2*pi;
Kang = 1/ecart_roue;

%%J = 35.9e-7;
%%f = 0.001109;
%%K = 0.0199;
%%R = 0.358;
%%L = 0.07e-3;
%%s = tf('s');
G = K/(s*((J*s+f)));

G01 = c2d(Kreduc*Kroue*G, 1/fe, 'zoh');
G02 = c2d(Kang*Kreduc*Kroue*G, 1/fe, 'zoh');
G01 = d2c(G01, 'Tustin');
G02 = d2c(G02, 'Tustin');

%% Définition du Correcteur
[C_pos, Pm1, wa1, wb1] = Regu_calc(G01, 2*fe*tan(wu/(2*fe)), 10, 80);
[C_ang, Pm2, wa2, wb2] = Regu_calc(G02, 2*fe*tan(wu/(2*fe)), 10, 80);

figure();
bode(C_pos);
grid on;

figure();
bode(C_ang);
grid on;

%% Affichage FTBO
FTBO = G01*C_pos;
FTBF = FTBO/(1+FTBO);

figure();
margin(FTBO);
figure();
bode(FTBF);

figure();
step(FTBF);
figure();
nyquist(FTBO);
figure();
nichols(FTBO);

%% Transformée en z du régulateur
%close all;
Tech = 1/fe ;
TZ1 = c2d(C_pos, Tech, 'Tustin');
TZ2 = c2d(C_ang, Tech, 'Tustin');
REGULATEUR1 = tf(TZ1.Numerator{1,1}, TZ1.Denominator{1,1}, Tech, 'variable', 'z^-1')
REGULATEUR2 = tf(TZ2.Numerator{1,1}, TZ2.Denominator{1,1}, Tech, 'variable', 'z^-1');
fileID = fopen('REGU_CST.hpp', 'w');
MAXORDER1 = max(length(REGULATEUR1.Numerator{1,1}), length(REGULATEUR1.Denominator{1,1}));
MAXORDER2 = max(length(REGULATEUR2.Numerator{1,1}), length(REGULATEUR2.Denominator{1,1}));
fprintf(fileID, '#define TAILLE_TABLEAUX_POS %d\n', MAXORDER1);
fprintf(fileID, '#define TAILLE_TABLEAUX_ANG %d\n', MAXORDER2);
fprintf(fileID, '#define TECH %f\n', Tech);
format1 = '%f';
for i = 2 : MAXORDER1
    format1 = strcat(format1, ',%f ');
end
fprintf(fileID, strcat('#define XCOEFFS_POS { ', format1, '}\n'), REGULATEUR1.Numerator{1,1});
fprintf(fileID, strcat('#define YCOEFFS_POS { ', format1, '}\n'), REGULATEUR1.Denominator{1,1});
format2 = '%f';
for i = 2 : MAXORDER2
    format2 = strcat(format2, ',%f ');
end
fprintf(fileID, strcat('#define XCOEFFS_ANG { ', format2, '}\n'), REGULATEUR2.Numerator{1,1});
fprintf(fileID, strcat('#define YCOEFFS_ANG { ', format2, '}\n'), REGULATEUR2.Denominator{1,1});
fclose(fileID);
%zsysy = zpk(REGULATEUR)
%zplane(zsysy.Z{1,1}, zsysy.P{1,1})