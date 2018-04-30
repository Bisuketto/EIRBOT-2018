clear all;
close;

x = 1000; % Distance en mm
perimetre_enc = 87.96e-3;
A = 250;
Vmax = 250;
Consigne = x ;%x*4096/perimetre_enc;

omega = Consigne/Vmax + Vmax/A;
alpha = Vmax/A;
beta = omega - Vmax/A;
t = [0: 0.01: omega];
if Consigne < 0
    A = -A;
    Vmax = -Vmax;
    omega = Consigne/Vmax + Vmax/A;
    alpha = Vmax/A;
    beta = omega - Vmax/A;
    t = [0: 0.01: omega];
end
if alpha < beta
    t1 = [0: 0.01: alpha];
    p1 = 0.5*A*t1.^2;
    v1 = A*t1;
    t2 = [alpha: 0.01: beta];
    p2 = 0.5*A*alpha^2 + Vmax*(t2-alpha);
    v2 = Vmax + t2*0;
    t3 = [beta: 0.01: omega];
    p3 = 0.5*A*alpha^2 + Vmax*(beta-alpha) + (Vmax)*(t3-beta) - 0.5*A*(t3-beta).^2;
    v3 = Vmax-A*(t3-beta);
    figure();
    title('Position');
    xlabel('t');
    ylabel('x');
    hold on;
    plot(t1, p1);
    plot(t2, p2);
    plot(t3, p3);
    figure();
    title('Vitesse');
    xlabel('t');
    ylabel('V');
    hold on;
    plot(t1, v1);
    plot(t2, v2);
    plot(t3, v3);
else
    omega = 2*sqrt(Consigne/A);
    gamma = omega/2;
    t1 = [0: 0.01: gamma];
    p1 = 0.5*A*t1.^2;
    v1 = A*t1;
    t3 = [gamma: 0.01: omega];
    p3 = 0.5*A*gamma^2 + (A*gamma)*(t3-gamma) - 0.5*A*(t3-gamma).^2;
    v3 = A*gamma-A*(t3-gamma);
    figure();
    title('Position');
    xlabel('t');
    ylabel('x');
    hold on;
    plot(t1, p1);
    plot(t3, p3);
    figure();
    title('Vitesse');
    xlabel('t');
    ylabel('V');
    hold on;
    plot(t1, v1);
    plot(t3, v3);
end