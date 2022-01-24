function [outputArg1,outputArg2] = uesercizio7(x)
%Eserciozio 7
%calcolare f(x)=(1-cos(x)^2)x^/2 e g(x)=sin(x)^2/x^2
%Queste formule danno risultati diversi, ovvero quella con il sen è più
%accurata, poichè il cos, quando l'angolo è piccolo, lo posso approssimare
%con 1-angolo^2, ma se l'angolo è molto piccolo, il suo quadrato potrebbe
%essere minore dell'epsilon macchina, e quindi angolo^2 non da contributo
%se sottratto a 1, ma prima ho 1-cos^2, quindi 1-1-angolo^2 che fa 0 e
%quindi ho un errore del 100%, perchè non dovrei avere 0.
%Infatti con il sen non ho problemi di questo tipo
end

