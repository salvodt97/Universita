function [k,r,sol,err,flag] = esercizio1(x,tol)
k=1;            %Numero di prodotti
r=1;            %Numero di cilci e indice del vettore x1
x1=single(x);   %I numeri devono essere in singola precisione, lo dice la traccia
sol(k)=x(k);    %Inizializzo il primo prodotto
nmax=200;       %Serve a interrompere il ciclo nel caso in cui l'errore non è mai maggiore della tolleranza
flag=0;
sol(k+1)=sol(k)*x1(r);      %prodotto iniziale
err(k)=3*eps('single');     %Stima del valore iniziale: moltiplicando tra loro 2 valori non rappresentabili correttamnete, ho 3 errori, ovvero i 2 errori dei numeri e quello della moltiplicazione: faccio il calcolo a mano e vedo che l'errore maggioro con 3u

while(err(k)<tol || k<=nmax)
    k=k+1;                  %Aumento la dimensione del vettore dei prodotti
    r=r+1;                  %Aumento la dimensione del vettore x1, cioè inserisco elementi nuovi
    if (r==length(x)+1)
        r=1;
    end
    sol(k)=sol(k-1)*x1(r);           %Calcolo un nuovo prodotto
    err(k)=err(k-1)+2*eps('single'); %Al passo corente stimo l'errore, che è pari all'errore precdente più l'errore nel rappresentare il nuovo elemento di x1 più l'erore del prodotto, che asereebero uguali?
    if(sol(k)>=realmax('single') || sol(k)<=realmin('single'))  %Vedo se il prodotto che ho fatto lo riesco a rappresentare, oppure no perchè è troppo piccolo o troppo grande
        k=k-1;                  %"Tolgo" il valore che sarebbe troppo grande per matlab (inf) o troppo piccolo(NaN)
        flag=1;                 %Dico cosa è successo
        break                   %Termino l'esecuzione, perchè anche il valore successivo sarà o troppo grande(più del precedente che era già troppo grande) o troppo piccolo
    end
end
end

