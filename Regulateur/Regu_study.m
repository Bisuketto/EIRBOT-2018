clear all;
close all;
clc;

prompt = {'Gain Statique', 'w0p', 'w0'};
dlgtitle = 'Paramètres G(p)';
line = 1; def = {'1', '1', '6.66'};
procede = inputdlg(prompt, dlgtitle, line, def);

G0 = str2num(char(procede(1)));
w0p = str2num(char(procede(2)));
w0 = str2num(char(procede(3)));
p = tf('s');
G = G0/((p/w0p)*(p/w0 + 1));
C = tf([1]);
%% Etude de l'asservissement

Choix = 0;

while(Choix ~= 5)
    Choix = menu('Etude de l''asservissement', 'Etude du procédé', 'Synthèse du régulateur', 'Etude en BO', 'Etude en BF', 'Quitter');
    switch Choix
        case 1;
            Choix1 = 0;
            while(Choix1 ~= 5)
                Choix1 = menu('Choix de l''etude', 'Bode', 'Nichols', 'Nyquist', 'Step', 'Retour');
                switch Choix1
                    case 1
                        figure();
                        margin(G);
                    case 2
                        figure();
                        nichols(G);
                    case 3
                        figure();
                        nyquist(G);
                    case 4
                        figure();
                        step(G);
                    otherwise
                        Choix1 = 5;
                end
            end
        case 2;
            prompt = {'wu', 'Marge de Phase'};
            dlgtitle = 'Performances Souhaitées';
            line = 1; def = {'10', '60'};
            procede = inputdlg(prompt, dlgtitle, line, def);
            wu = str2num(char(procede(1)));
            MP = str2num(char(procede(2)));
            
            C = Regu_calc(G, wu, 10, MP);
        case 3;
            Choix2 = 0;
            while(Choix2 ~= 4)
                Choix2 = menu('Choix de l''etude', 'Bode', 'Nichols', 'Nyquist', 'Retour');
                switch Choix2
                    case 1
                        figure();
                        bode(G*C);
                    case 2
                        figure();
                        nichols(G*C);
                    case 3
                        figure();
                        nyquist(G*C);
                    otherwise
                        Choix2 = 4;
                end
            end
        case 4;
            Choix3 = 0;
            numG = G.Numerator{1,1};
            denG = G.Denominator{1,1};
            numC = C.Numerator{1,1};
            denC = C.Denominator{1,1};
            
            start_time = 0.0;
            stop_time = 10.0;
            t_e = 1.0;
            t_pu = 5.0;
            t_ps = 7.0;
            ival_e = 0; ival_pu = 0; ival_ps = 0;
            val_e = 1; val_pu = 1; val_ps = 1;
            Rtol = 1e-3;
            
            omega = logspace(0,3,100);
            [a,b,c,d] = linmod('sc_Regu_Study');
            
            while(Choix3 ~= 3)
                Choix3 = menu('Choix de l''etude', 'Frequentielle', 'Temporelle', 'Retour');
                switch Choix3
                    case 1
                        Choix4 = 0;
                        while(Choix4 ~= 4)
                            Choix4 = menu('Transferts', 'Y/E', 'Y/P', 'Y/FF', 'Retour');
                            switch Choix4
                                case 1
                                    [g,p] = bode(a,b,c,d,1,omega);
                                    gdB = 20*log10(g);
                                    figure
                                    subplot(2,1,1);
                                    semilogx(omega,gdB(:,1));
                                    subplot(2,1,2);
                                    semilogx(omega,p(:,1));
                                case 2
                                    [g,p] = bode(a,b,c,d,3,omega);
                                    gdB = 20*log10(g);
                                    figure
                                    subplot(2,1,1);
                                    semilogx(omega,gdB(:,1));
                                    subplot(2,1,2);
                                    semilogx(omega,p(:,1));
                                case 3
                                    [g,p] = bode(a,b,c,d,2,omega);
                                    gdB = 20*log10(g);
                                    figure
                                    subplot(2,1,1);
                                    semilogx(omega,gdB(:,1));
                                    subplot(2,1,2);
                                    semilogx(omega,p(:,1));
                                otherwise
                                    Choix4 = 4;
                            end
                        end
                    case 2
                        Choix5 = 0;
                        prompt = {'Ste', 'Ive', 'Fve', 'Stpu', 'Ivpu', 'Fvpu', 'Stps', 'Ivps', 'Fvps'};
                        dlgtitle = 'Echelons';
                        line = 1; def = {'1', '0', '1', '5', '0', '1', '7', '0', '1'};
                        procede = inputdlg(prompt, dlgtitle, line, def);
                        t_e = str2num(char(procede(1)));
                        ival_e = str2num(char(procede(2)));
                        val_e = str2num(char(procede(3)));
                        t_pu = str2num(char(procede(4)));
                        ival_pu = str2num(char(procede(5)));
                        val_pu = str2num(char(procede(6)));
                        t_ps = str2num(char(procede(7)));
                        ival_ps = str2num(char(procede(8)));
                        val_ps = str2num(char(procede(9)));
                        
                        [t,x,y] = sim('sc_Regu_Study');
                        
                        while(Choix5 ~= 3)
                            Choix5 = menu('Graphes', 'Commande', 'Sortie', 'Retour');
                            switch Choix5
                                case 1
                                    plot(t, y(:,2));
                                case 2
                                    plot(t, y(:,1));
                                otherwise
                                    Choix5 = 3;
                            end
                        end
                    otherwise
                        Choix3 = 3;
                end
            end
        otherwise
            Choix = 5;
    end
end