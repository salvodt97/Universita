function [outputArg1,outputArg2] = untitled5(inputArg1,inputArg2)
%Esercizio 4: sto calcolando una successione con 2 formule:
%1)xk=xk-1+h; così uso ogni volta il valore precedente, e quindi con ohni xk
%  mi porto dietro eventuali errori di round-off del valore precedente
%2)xk=x0+(k-1)*h; questa formula contiene meno errori, poichè ogni volta uso
%  il valore iniziale x0 che supponiamo essere corretto: quindi l'unico
%  errore che potremo avere è quello di amplificazione di (k-1)*h, che
%  comunque è minore dell'accumulo del caso 1
%Ovviamente tutta questa analisi è teorica; il risultato corretto lo devo
%conoscere io a priori, o almeno una stima. ALtrimenti, uso più algoritmi
%per sapere quali delle 2 formule si avvicina di più.
end

