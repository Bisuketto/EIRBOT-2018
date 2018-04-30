close all;

t = [0 : 0.005 : 499*0.005];
plot(t, speed2);
grid on;

Vf = mean(speed2(200:length(speed2)));
tm = 0.145;
Vf2 = 496.6171;
tm2 = 0.0447;