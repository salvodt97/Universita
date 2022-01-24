function [x, condizionamento, e] = esercizio1()
%Esercizio 1: la mia mtricola è M63001011, e per far si che non sia
%singolare la matrice che formo, sostitusco 1011 con 1611.
M=rand(10);     %creo una matrice casuale 10x10
m=[1 6 1 1];    %Matricola
m1=M .* m(1);         %Primo blocco della dagonale
m2=M .* m(2);         %Secondo blocco della diagonale
m3=M .* m(3);         %Terzo blocco
m4=M .* m(4);         %Quarto blocco

A=blkdiag(m1, m2, m3, m4);  %A è una matrice diagonale a blocchi
A1=sparse(A);    %Per ottimizzare lo spazio uso una matrice sparsa

b1=rand(10,1);  %Il primo blocco di b è random

%Ogni blocco b(i+1) lo calcolo come x(i)*m(4-i), quindi calcolo ogni
%x(i)=b(i)\m(i)
x1=m1\b1;
b2=m3*x1;

x2=m2\b2;
b3=m2*x2;

x3=m3\b3;
b4=m1*x3;

b=[b1; b2; b3; b4];

%Risolvo il sistema Ax=b;
x=A1\b;         %Lo risolvo con la matrice sparsa

%Stimo l'accuratezza del risultato con il residuo
condizionamento=cond(A);
r=norm(b-A1*x)\norm(b);     %Calcolo del rsiduo
e=condizionamento*r;                %Calcolo dell'errore

%In aritmetica a precisione infinita so che il residuo è nullo, e quindi
%anche l'errore, ma in matlab (a precisione finita) non lo è.

end

