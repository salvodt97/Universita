function [z] = esercizio6(x)
%Esercio 6
%ccalcolare z=1/[sqrt(x^2+1)-x]
z=1/[sqrt(x^2+1)-x]
%Abbiamo trovato i valori per i quali ci sono casi eccezionali: il problema
%� quando x � molto grande, e la funzioarmi inf
%si potrebbe usare z=sqrt(x^1+1)+x; questa formula � equivalente a quella
%di prima, ma � pi� accurata e non mi da problemi per valori di x molto
%grandi; con la seconda formula ho razionalizzato, quindi evito il problema
%dell'epsilon macchina, nel aso in cui x^2 � molto pi� piccolo di 1; ma non
%risolvo comunque il problema se x � molto grande, poch� allora x^2 sarebbe
%molto pi� grande di 1, ovvero 1 potrebbe essere pi� piccolo dell'epsilon
%macchina relativo a x, e quindi 1 non mi da contributi nella somma: matlab
%quindi vedrebbe sqrt(x^2)-x e mi darebbe 0.
%Questo problema non lo riesco a risolveere cos�: allora lo scalo,
%normalizzo, ovvero divido tutti i numeri di sqrt per il numero pi� grande
%cos� da evitare errori.
end

