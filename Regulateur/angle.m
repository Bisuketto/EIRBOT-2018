clear;
close;

nb_pts = 1000;

theta = 360; %Degres
rad = theta*pi/180;
r = (360e-3)/2;
perimetre_enc = 87.96e-3;
x = r*rad*4096/perimetre_enc;

A = 5000; %Acceleration angulaire rad.s^-2
Vmax = 10000; %Vitesse angulaire rad.s^-1
Consigne = x; %Angle

omega = Consigne/Vmax + Vmax/A;
alpha = Vmax/A;
beta = omega - Vmax/A;
t = [0: omega/nb_pts: omega];
if Consigne < 0
    A = -A;
    Vmax = -Vmax;
    omega = Consigne/Vmax + Vmax/A;
    alpha = Vmax/A;
    beta = omega - Vmax/A;
    t = [0: omega/nb_pts: omega];
end
if alpha < beta
    t1 = [0: alpha/nb_pts: alpha];
    p1 = 0.5*A*t1.^2;
    v1 = A*t1;
    t2 = [alpha: (beta-alpha)/nb_pts: beta];
    p2 = 0.5*A*alpha^2 + Vmax*(t2-alpha);
    v2 = Vmax + t2*0;
    t3 = [beta: (omega-beta)/nb_pts: omega];
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
    t1 = [0: gamma/nb_pts: gamma];
    p1 = 0.5*A*t1.^2;
    v1 = A*t1;
    t3 = [gamma: (omega-gamma)/nb_pts: omega];
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