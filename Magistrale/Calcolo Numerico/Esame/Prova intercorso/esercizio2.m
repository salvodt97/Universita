clear all
clc

x=-300:0.1:300;
y=f(x);
plot(x,y);

%Introduco ora una perturbazione sui dati deltax
deltax=0.07;

x1=1;
cond_1=abs((f(x1+deltax)-f(x1))/deltax)
%Dall'esecuzione si è visto che il problema è mal condizionato se x=1

x2=100;
cond_2=abs((f(x2+deltax)-f(x2))/deltax)
%In questo caso il problema è ben condizionato.