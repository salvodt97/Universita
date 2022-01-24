function [m1,m2]=puntomedio(a,b)
%Imposto singola precisione
a1=single(a)
b1=single(b)
%Calcolo il punto medio con queste 2 formule, che sono diverse:
m1=a1+(b1-a1)/2     %Questa è più precisa, non mi da errori di round-off
m2=(a1+b1)/2        %Quetsa mi da problemi quando i due numeri sono molto vicini e mi trovo a fare una sottrazione
%Cioè potrei avere delle cancellazioni catastrofiche
end

