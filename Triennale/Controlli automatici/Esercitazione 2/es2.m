close all;
clear all;
syms s;

%Definisco l'impianto
ng=30*(1+0*s);
dg=(s+5)*(s+1)^2;
numg=sym2poly(ng);
deng=sym2poly(dg);
G=tf(numg,deng);
[Gm,Pm,Wcg,Wcp] = margin(G);

%Creo i parametri d utili per proggettare il pid
Kpc=Gm;
T=2*pi/Wcg;
pid.Kp=0.6*Kpc;
pid.Ti=0.5*T;
pid.Td=0.125*T;

%Definisco il pid
nk=(pid.Kp/pid.Ti)*(1+pid.Ti*s+pid.Ti*pid.Td*(s^2));
dk=s*(1+s/1000);
num=sym2poly(nk);
den=sym2poly(dk);
K=tf(num,den);

F=K*G;
[Gmf,Pmf,Wcgf,Wcpf] = margin(F);
figure;
margin(F);
figure;
y=feedback(F,1);
step(y,20);

%Calcolo ora  tempi di assestamento per vedere se mi trovo
zita=Pmf/100;
sovraelong=exp(-(pi*zita)/(sqrt(1-zita^2)));
ta5=3/(zita*Wcpf);
ta1=4.6/(zita*Wcpf);



%vedo se la risposta al gradino è in socillazione permanente
% numkp=Kpc*(1+0*s);
% denkp=1*(1+0*s);
% nkp=sym2poly(numkp);
% dkp=sym2poly(denkp);
% KP=tf(nkp,dkp);
% 
% F1=KP*G;
% figure;
% oscilla=feedback(F1,1);
% step(oscilla,10);

