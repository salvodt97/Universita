function [k,x] = esercizio5(a, b, M)
%Input: a,b,M sono scalari
%Output: k numero di iterazioni; x valore corrente
%M=2;
%a=1;
%b=2;
k=0;
while b-a > eps(b)
    x(k+1)= (a +(b-a)/2); %Uso questa formula invece di (a+b)/2 perchè altrimenti si potrebbe avere cancellazione catastrofica se in modilo a e b sono molto vicini, e il risultato potrebbe essere scoretto
    if (x(k+1))^2 - M > eps(x(k+1)^2) %Confrontare con l'epsilon di x^2 o con l'epsilon di M è la stessa cosa.
        b = x(k+1);
    else
        a = x(k+1);
    end
    k=k+1;
end
end

