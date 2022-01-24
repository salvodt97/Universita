function [eps_cal] = eps1(nmax)
%Quetsa funzione crea l'epsilon macchina, e nmax è il numero di iterazioni
%massima, si fa proprio così
n=0;
eps_cal=0.5;    %Partiamo da 0.5 poichè matlab usa l'arrotondamento; se fosse l'incremento si partirebbe da 1
eps2=eps_cal+1;

while(eps2>1 && n<nmax)
    n=n+1;
    eps_cal=0.5*eps_cal;
    eps2=eps_cal+1;
end
eps_cal=2*eps_cal;
end

%Il nome del file deve essere lo stesso della function
%Praticamente l'algoritmo calcola l'esponente 1-t della base, e parto da
%0.5 poichè è la mantissa che già conosco
