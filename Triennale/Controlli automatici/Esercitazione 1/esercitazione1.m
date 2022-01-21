close all
clear all
syms s
numk=25*(1+s/2)*(1+s/100)
denk=s
nk=sym2poly(numk)
dk=sym2poly(denk)
K=tf(nk,dk)

numg=30*(1+0*s)
deng=(s+10)*(s+3)
ng=sym2poly(numg)
dg=sym2poly(deng)
G=tf(ng,dg)

F=K*G
figure
margin(F)