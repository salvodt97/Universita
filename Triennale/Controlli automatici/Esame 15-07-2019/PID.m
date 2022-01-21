close all
clear all
syms s

%Definisco l'impianto
numg=5*(1+0*s)
deng=(10+s)*(s+1)*(s+5)
ng=sym2poly(numg)
dg=sym2poly(deng)
G=tf(ng,dg)
[Gmg,Pmg,Wcgg,Wcpg]=margin(G)

%Parametri del pid
T=2*pi/Wcgg
kpc=Gmg
pid.Kp=0.45*kpc
pid.Ti=0.8*T

%Definisco il pid PI
numk=(pid.Kp/pid.Ti)*(1+pid.Ti*s)
denk=s
nk=sym2poly(numk)
dk=sym2poly(denk)
K=tf(nk,dk)
F=K*G
[Gmf,Pmf,Wcgf,Wcpf]=margin(F)

%Calcolo la risposta al gradino
y=feedback(F,1)
figure
step(y,10)

%Parametri risposta al gradino
zita=Pmf/100
sovraelongazione=exp((-pi*zita)/sqrt(1-zita^2))
ta5=3/(zita*Wcpf)
ta1=4.6/(zita*Wcpf)