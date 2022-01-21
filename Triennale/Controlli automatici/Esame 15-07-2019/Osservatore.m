close all
clear all
clc

%Sistema nello spazio di stato
A=[-1 3; 2 0]
B=[1; 1]
C=[0 1]

eigA=eig(A)                 %Autovalori originali

Mr=ctrb(A,B)                %check raggiungibilita'
rankMr=rank(Mr)             %Vedo che il sistma non è completamente raggiungibile

%Definisco l'osservatore
eig_obs=[-10 -30];          %autovalori desiderati per l'osservatore
Gt=acker(A',C',eig_obs)
G=Gt'


%Definisco ora il controllore nel caso voglio errore di inseguimento nullo:
%in questo caso avrò 3 autovalori: 2 per il controllore,che saranno quelli
%dell'osservatore ma 10 volte più lenti, e uno assegnato. Quindi:
% eig_cont=[ -1 -3 -2]   %Il -2 l'ho messo io come terzo autovalore
% n=size(A,1);
% Amod=[A zeros(n,1); -C 0]
% Bmod=[B;0]
% K=-acker(Amod, Bmod, eig_cont)

