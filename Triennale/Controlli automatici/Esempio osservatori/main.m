clc
clear all
close all

%% processo terzo ordine (descrizione nello spazio di stato)
A=[0 1 0; 0 -1 1; 0 0 -5];
B=[0 0 5]';
C=[1 0 0];
n=size(A,1);
x0=[2 1 0];

% funzione  di trasferimento associata

[numP,denP] = ss2tf(A,B,C,0);
Process=tf(numP,denP);

% autovalori originari
sigmaA=eig(A);

% check raggiungibilita'
Mr=ctrb(A,B);
rankR=rank(Mr);

% autovalori desiderati
eig_cl_des=[-1+2j -1-2j -10]; 

% stabilizzazione con reazione dinamica dello stato
progStateFeedback
keyboard


% stabilizzazione con reazione dinamica dello stato con aggiunta di un
% ciclo esterno di controllo con azione integrale per specifiche di regime
progStateFeedbackIntegralAct
keyboard

% stabilizzazione con osservatore di stato e 
% ciclo esterno di controllo con azione integrale per specifiche di regime
progStateFeedbackIntegralActObs

