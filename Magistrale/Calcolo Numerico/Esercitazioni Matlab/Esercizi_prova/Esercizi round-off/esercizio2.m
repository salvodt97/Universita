function [valore, controllo] = esercizio2(p)
%Dati di input della funzione
 x=10*pi;
 z=10^(-p);
 valore=x/(x+z^2);
 %Definisco ora l'epsilon relativo ad x
 epsx=abs(x)*eps;
 %Ora so che se z^2<epsx, se lo sommo ad x il suo valore non viene visto,
 %quindi controllo questo
 if(z^2<epsx)
     controllo='z^2 non da contributo';
 else
     controllo='z^2 da contributo';
 end
 
end

