Tm = 3.24e-3;
Te = 0.195e-3;
Kv = 393;
G = idtf(Kv, [Te*Tm Te+Tm 1]);
bode(G);