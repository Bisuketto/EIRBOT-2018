function [ C, PhiM, va, vb, Gw] = Regu_calc_W( G, wu, integ, MF, Tech )
    s = tf('s');
    
    Gz = c2d(G, Tech, 'zoh');
    [Gnum, Gden] = tfdata(Gz);
    Gz2 = tf(Gnum, Gden, 2);
    Gw = d2c(Gz2, 'tustin');
    
    Ti = integ/wu;
    Tf = 1/(integ*wu);
    
    vu = tan(wu*Tech/2);
    %vi = vu;
    %vf = vu;
    vi = tan(Tech/(2*Ti));
    vf = tan(Tech/(2*Tf));
    
    I = (1+vi*s)/(vi*s);
    F = 1/(1+vf*s);
    [~, PHASE_IFU] = bode(Gw*I*F, vu);
    PhiM = (MF - 180 - PHASE_IFU);
    a = (1+sin(PhiM*pi()/180))/(1-sin(PhiM*pi()/180));
    va = 1/(sqrt(a)/vu);
    vb = (sqrt(a)*vu);
    
    %va = tan(wa*Tech/2);
    %vb = tan(wb*Tech/2);
    
    D = ((1+(1/va)*s)/(1+(1/vb)*s));
    [GAIN, ~] = bode(I*D*F*Gw, vu);

    P = 1/(GAIN);
    
    C = P*I*D*F;
    
    %figure();
    %margin(Gw*C);
end

