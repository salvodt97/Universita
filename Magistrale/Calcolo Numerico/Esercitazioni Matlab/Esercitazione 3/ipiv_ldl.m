function [L,U,ipiv] = ipiv_ldl(A)
[L,U,ipiv]=lu(A,'vector');


%Con [A]=lu(A) non stampo le matrici L e U, ma le salvo direttamnete nella
%matrice A, la sovrascrivo per non sprecare spazio.
%Per matrici simmetriche si usa la fattorizzazione LDL', facendo
%[L,D]=ldl(A);   L sar� come la L della fattorizzazione LU, invece D
%sar� ..............
%Questo serve per evitare di fare troppe operazioni inutili, poich� ogni
%sosstomatrice sar� simmetrica
end

