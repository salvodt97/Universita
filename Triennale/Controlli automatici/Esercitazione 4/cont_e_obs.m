close all
clear all
clc
syms s

%Impianto
numg=30*(1+s/0.5)*(1+s/0.2)
deng=s*(1+0.5*s+4*s^2)*(1+s/0.05)
Ng=sym2poly(numg)
Dg=sym2poly(deng)
G=tf(Ng,Dg)
figure
margin(G)

%K'
numk1=(1/6)*(1+0*s)
denk1=1+0*s
nk1=sym2poly(numk1)
dk1=sym2poly(denk1)
K1=tf(nk1,dk1)

%K''
numk2=8*(1+s/0.5)
denk2=(1+s/20)
nk2=sym2poly(numk2)
dk2=sym2poly(denk2)
K2=tf(nk2,dk2)

F=G*K1*K2
figure
%nichols(F)
margin(F)