function [m,i]=esercizio2(m1)
%Calcola la successione dei puti medi mi+1 degli intervalli [1,mi], dove m1
%sarebbe il dato e termina non appena si raggiunge la minima distanza 1
i=1;
m(i)=m1;
while(m(i)-1>eps)   %Il while termona quando raggiungo l'epsilon macchina
    i=i+1;
    m(i)=1+(m(i-1)-1)/2;     %Uso questa formula per evitare di avere errori di round-off
end

%Con la funzione single, per esempio a1=single(a), lavoro in singola
%precisione

