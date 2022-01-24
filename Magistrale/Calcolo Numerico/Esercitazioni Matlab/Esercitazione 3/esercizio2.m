function [condizionamento, condizionameno_cond] = esercizio2(A, b)
%Calcolare la soluzione di Ax=b e una approssimazione dell'indice di cond
%Vevamo visto per l'esempio A=[1 1; 0.0001 1] e b=[2 1]
A1=single(A);
b1=single(b');
x=A1\b1;

delta_b=single([0.0001 1]'); %Aggiungo una piccola perturbazione nei dati di ingreso
x1=A1\(b1+delta_b);

err_sol=norm(x1-x)/norm(x);
err_dati=norm(delta_b)/norm(b);
condizionamento=err_sol/err_dati;
condizionameno_cond=cond(A);

%Stiamo così calcolando la distanza tra le soluzioni e la distanza tra i
%dati in gresso, per calcolare poi manualmente l'indice di condizionamento.
%Tale valore manuale viene un po' più grande dell'indice calcolato con
%cond(A)
end

