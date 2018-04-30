clc
close all
clear all

size = 800;
a = 3;
b = 1;
posX = 150;
posY = 100;
c = -a*posX - b*posY;
[X, Y] = meshgrid(0:size-1, 0:size-1);
D1 = uint8(a*X + b*Y + c == 0);
D2 = uint8(-b*X + a*Y - (-b*posX + a*posY) == 0);


img = rot90(cat(3,(D1+D2).', D1.', D1.'))*255;
figure, image(img), axis image, grid on, grid minor;