close all
clear all
syms s

%Definisco l'impianto
numg=(50+25*s)
deng=(10+s)*(s^2 + 0.7*s + 0.1)
ng=sym2poly(numg)
dg=sym2poly(deng)
G=tf(ng,dg)
figure
margin(G)

%Definisco il controllore K'
numk1=20*(1+0*s)
denk1=1+0*s
nk1=sym2poly(numk1)
dk1=sym2poly(denk1)
K1=tf(nk1,dk1)
F1=K1*G
figure
margin(F1)

% %Definisco il controllore K'' fatto all'esame
% numk2=(1+s/100)
% denk2=1+s/1000
% nk2=sym2poly(numk2)
% dk2=sym2poly(denk2)
% K2=tf(nk2,dk2)
% F2=K2*F1
% figure
% margin(F2)


%Definisco il controllore K'' corretto
numk2=3.5*(1+s/100)*(1+s/1)
denk2=1+s/0.1
nk2=sym2poly(numk2)
dk2=sym2poly(denk2)
K2=tf(nk2,dk2)
F2=K2*F1
figure
margin(F2)