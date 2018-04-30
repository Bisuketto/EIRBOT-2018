clc;
close all;
clear all;

%% Definition du procédé identifié

Kreduc = 1/5.8;
Kroue = 90.14*2.1428;
ecart_roue = 181.25*2;
Kang = 2/ecart_roue;
Kang = Kang*180/pi;
K1 = 313/(0.30*18);%Kreduc*Kroue*313/(0.30*18);
K2 = 496*Kang/(0.30*18*2);%Kang*Kreduc*Kroue*313/(0.30*18);
Tm = 0.145;
Tm_ang = 0.045;
s = tf('s');
G1 = K1/(s*(1+Tm*s));
G2 = K2/(s*(1+Tm_ang*s));
Smax = 500;
ASmax = pi/12;
ASmax = 180;
Vmax = 18;

wm = 1/Tm;
wm_ang = 1/Tm_ang;
wu = 5*wm;
fu = wu/(2*pi);
fech_th_min = 10*fu;
fech_th_min_ang = 10*5*wm_ang/(2*pi);

Fech = 200;
Tech = 1/Fech;

[C_pos, PhiM_pos, wa_pos, wb_pos] = Regu_calc(G1, 5*wm, 5, 54);
[C_ang, PhiM_ang, wa_ang, wb_ang] = Regu_calc_2D(G2, 3*wm_ang, 5, 90);
[C_posW, PhiM_posW, va_pos, vb_pos, Gw1] = Regu_calc_W(G1, 5*wm, 5, 54, Tech);
[C_angW, PhiM_angW, va_ang, vb_ang, Gw2] = Regu_calc_W(G2, 5*wm_ang, 5, 54, Tech);


% G = G1;
% C = C_pos;
% figure();
% bode(G);
% figure();
% margin(G);
% figure();
% bode(C*G/(1+C*G));
% figure();
% margin(C*G);
% figure();
% nyquist(C*G);
% figure();
% nichols(C*G);
% figure();
% step(C*G/(1+C*G));

%Tech = 1/fech_th ;
TZ1 = c2d(C_pos, Tech, 'foh');
TZ2 = c2d(C_ang, Tech, 'foh');
TW1 = c2d(C_posW, Tech, 'tustin')
TW2 = c2d(C_angW, Tech, 'tustin')
REGULATEUR1 = tf(TW1.Numerator{1,1}, TW1.Denominator{1,1}, Tech, 'variable', 'z^-1');
REGULATEUR2 = tf(TW2.Numerator{1,1}, TW2.Denominator{1,1}, Tech, 'variable', 'z^-1');
fileID = fopen('REGU_CST.hpp', 'w');
MAXORDER1 = max(length(REGULATEUR1.Numerator{1,1}), length(REGULATEUR1.Denominator{1,1}));
MAXORDER2 = max(length(REGULATEUR2.Numerator{1,1}), length(REGULATEUR2.Denominator{1,1}));
fprintf(fileID, '#define TAILLE_TABLEAUX_POS %d\n', MAXORDER1);
fprintf(fileID, '#define TAILLE_TABLEAUX_ANG %d\n', MAXORDER2);
fprintf(fileID, '#define TECH %f\n', Tech);
format1 = '%f';
for i = 2 : MAXORDER1
    format1 = strcat(format1, ',%ef ');
end
fprintf(fileID, strcat('#define XCOEFFS_POS { ', format1, '}\n'), REGULATEUR1.Numerator{1,1});
fprintf(fileID, strcat('#define YCOEFFS_POS { ', format1, '}\n'), REGULATEUR1.Denominator{1,1});
format2 = '%f';
for i = 2 : MAXORDER2
    format2 = strcat(format2, ',%ef ');
end
fprintf(fileID, strcat('#define XCOEFFS_ANG { ', format2, '}\n'), REGULATEUR2.Numerator{1,1});
fprintf(fileID, strcat('#define YCOEFFS_ANG { ', format2, '}\n'), REGULATEUR2.Denominator{1,1});
fclose(fileID);