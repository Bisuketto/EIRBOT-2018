function [ C, PhiM, wa, wb ] = Regu_calc_2D( G, wu, integ, MF )
    s = tf('s');
    
    ti = integ/wu;
    Tf = 1/(integ*wu);
    I = (1+ti*s)/(ti*s);
    F = 1/(1+Tf*s);
    [~, PHASE_IFU] = bode(G*I*F, wu);
    PhiM = (MF - 180 - PHASE_IFU)/2;
    a = (1+sin(PhiM*pi()/180))/(1-sin(PhiM*pi()/180));
    wa = 1/(sqrt(a)/wu);
    wb = (sqrt(a)*wu);
    D = ((1+(sqrt(a)/wu)*s)/(1+(1/(sqrt(a)*wu))*s));
    [GAIN, ~] = bode(I*D*D*F*G, wu);

    P = 1/(GAIN);
    
    C = P*I*D*D*F;
end