function [L,U,P, determinanteA] = fattorizzazione_lu(A)
%Abbiamo usato per l'esempio A=[22 1 4 3; 10 40 3 2; 1 4 20 6; 4 3 2 45];
%in particolare era una matrice che non richiedeva scambio di righe, in
%quanto i pivot già sono gli esercizi più grandi, e quindi avremo che P=I

[L,U,P]=lu(A) ;       %Con questo comando sto facendo la fattorizzazione LU, che mi calcola le matrici L, U, e quella di permutazione
%Riottengo A scrivenfo A=P'*L*U: in realtà dovrei fare l'inversa di P, cioè
%A=inv(P)*L*U, ma visto che P è una permutazione di I, l'inversa coincide
%con la trasposta.

determinanteA=prod(diag(U));
%con diag estraggo la diagonale di U, e con prod(x) faccio il prodotto tra
%tutti gli ementi di x: quindi con diag(U) etstraggo la diagonale di U e
%poi faccio il prodotto degli elementi 

%A=10*diag(rand(5,1)+diag(rand(4,1),-1)+diag(rand(4,1)+1); così creo una
%matrice tridiagonale con diagonale dominante

%Con S=sparse(A) salvo la matrice A come sparsa, e poi se faccio lu(S), la
%fattorizzazione mi mostra solo gli elementi non nulli, poichè fa
%operazioni solo su elementi diversi da 0: ciò serve ad ottimizzare. Così
%otimizzo anche la memoria, in quanto salvo solo gli elementi non nulli.+
%Con full(P) invece ritorno alla matrice normale con gli zeri.

end

