%Sia a una variabile aleatoria con distribuzione uniforme nell'intervallo
%[-0.5 0.5], contarequanti elementi di a sono minori di 0

clear all
clc

n=input('inserire numero di elementi nel vettore \n');

a=rand(n,1)-0.5    %Sottraggo 0.5 perchè rand lo fa tra 0 e 1

cont=0;
for i=1:n       %con 1:n sto guardando gli elementi n di passo 1, cioè li guardo tutti
    if a(i)<0
        cont=cont + 1;
    end
end

fprintf('Il numero di elementi minori di 0 è %f\n', cont)