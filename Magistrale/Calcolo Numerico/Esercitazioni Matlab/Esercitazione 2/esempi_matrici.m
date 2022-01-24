function [outputArg1,outputArg2] = untitled9(inputArg1,inputArg2)
end
%Per risolvere un sistema in matlab si usa il simbolo \, ovvero x=A\b.
%Questo operatore usa algoritmi diversi: confronta A con trill(A) per
%vedere se A è triangolare inferiore, e in questo caso usa l'algoritmo
%forward per risolvere; e la confronta con triu(A9 per vedere se è
%triangolare superiore: in questo caso usa Back substitution.
%Se non vale nessuna delle 2, usa Gauss con pivoting.
%Tale operatore controlla anche se la matrice è singolare, e noto ciò se
%nel risultato una delle componenti di x è inf o NaN.
%Controlla anche se la matrice è rettangolare(non quadrata) e , se ha
%infinite soluzioni, me ne restituisce una arbitraria.
%La matrice di hilbert si calcola con gli elemeti hij=(i+j-1)^-1, ovvero i
%termini sono tute frazioni che diventano via via più piccole(solo il primo
%elemento è 1). Più sono gli elementi, più il condizionameto di H(cond(H))
%cresce e tende all'infinito.
%In questo caso comunque il cndizionamento è >1 sempre: si cerca quindi il
%caso migliore.
%Se volessi vedere se il risultato fatto con \ è corretto, vado a calcolare
%il residuo, ovvero con norm(b-A*x)/norm(b); comunque non mi garantisce che
%anche l'errore relativo sul risultato sia piccolo, potrebbero essere
%diversi, e ciò dipende dal condizinamento.
%Addirittura se Hilbert è molto grande, gli elementi potrebbero essere
%talmente piccoli che la matrice per l'operatore \ potrebbe essere
%singolare(poichè ci sono elementi minori dell'epsilon macchina che matlab
%vede come se fossero 0)

%Per quanto riguarda il residuo, in realtà io vorrei che fsse nullo, ma in
%precisione finita non è così: più è piccolo però, più posso considerare
%buona la soluzione del sistema.
