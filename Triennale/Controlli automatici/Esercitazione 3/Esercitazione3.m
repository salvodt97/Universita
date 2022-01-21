close all
clear all
syms s

%G
numg=0.01*(1+0*s)
deng=(1+s)*(1+s/20)*(1+s/50)
ng=sym2poly(numg)
dg=sym2poly(deng)
G=tf(ng,dg)
[Gmg,Pmg,Wcgg,Wcpg] = margin(G)

%Parametri pid
kpc=Gmg
T=2*pi/Wcgg
pid.kp=0.6*kpc
pid.Ti=0.5*T
pid.Td=0.125*T

%PID
numk=(pid.kp/pid.Ti)*(1+pid.Ti*s+pid.Ti*pid.Td*s^2)
denk=s*(1+s/5000)
nk=sym2poly(numk)
dk=sym2poly(denk)
K=tf(nk,dk)

%Risposta al gradino
F=K*G
y=feedback(F,1)
figure
step(y,2)

%Parametri risposta al gradino
[Gmf,Pmf,Wcgf,Wcpf] = margin(F)
zita=Pmf/100
sovraelongazione=exp((-pi*zita)/(sqrt(1-zita^2)))
ta5=3/(zita*Wcpf);
ta1=4.6/(zita*Wcpf);
