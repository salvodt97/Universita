function [sum,sum2] =	somma(n)
sum=0;
sum2=0;
%Adesso lo scopo � quello di sommare tra loro grandezze che diventano via
%via sempre pi� piccoli
for j=1:n 
    sum=sum+(10^(-10))*eps/j; %Qua invece sommo termini sempre pi� piccoli, quindi quelli pi� piccoli dopo un po' non daranno contributo
end

for j=n:-1:1 %cos� parte da 100000 e ogni volta decrementa j
    sum2=sum2+(10^(-10))*eps/j; %Qui la somma parte al contrario: quindi la somma man mano cresce di grandezza, ovvero parto dai termini pi� piccoli e quindi tutti i termini danno contributo
end

end

%Da questo capisco che conviene sommare prima i termini pi� piccoli e
%manmano quelli pi� grande, cos� da avere contributi
%Questo esempio fa anche vedere il round-off, perch� nonstante le due
%operazioni in aritmetica infinita diano lo stesso risultato, qua danno un
%risultato diverso sulle cifre significative pi� piccole