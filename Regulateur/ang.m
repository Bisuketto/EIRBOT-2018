clc;
clear all;
close all;

x = [-pi : pi/512 : pi];
circle = exp(1i*x);
angl = [];
t = [];

for c = circle
    t = [t, 2*atan(imag(c)/(real(c)+1))];
    angl = [angl, mod( 2 * atan(imag(c)/real(c)), pi)];
end

figure();
%plot(x, angl);
hold on;
plot(x, t);
plot(x, imag(circle));
plot(x, real(circle));
grid minor;
grid on;