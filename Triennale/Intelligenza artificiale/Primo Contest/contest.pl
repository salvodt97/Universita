:- dynamic (arma/1).
:- dynamic (spada/1).
:- dynamic (arco/1).

mostro(rathian, fuoco, 1).
mostro(rathalos, fuoco, 2).
mostro(teostra, fuoco, 3).
mostro(daimyo, acqua, 1).
mostro(plesioth, acqua, 2).
mostro(kirin, tuono, 2).
mostro(rajang, tuono, 3).
mostro(zamtrios, ghiaccio, 1).
mostro(kushala, ghiaccio, 3).

volante(teostra).
volante(rathalos).
volante(kushala).

debolezza(rathian, acqua).
debolezza(rathalos, acqua).
debolezza(teostra, acqua).
debolezza(daimyo, tuono).
debolezza(plesioth, tuono).
debolezza(kirin, terra).
debolezza(rajang, terra).
debolezza(zamtrios, fuoco).
debolezza(kushala, fuoco).

arma(fuoco).
arma(tuono).
arma(ghiaccio).
arma(acqua).

spada(fuoco).
spada(tuono).
spada(ghiaccio).
spada(acqua).

arco(fuoco).
arco(tuono).
arco(ghiaccio).
arco(acqua).

acquistabile(X,[X|_C]).
acquistabile(X,[_T|C]):- acquistabile(X,C).

difficolta(X,Y,C):- arma(Y), debolezza(X,Y), mostro(X,_Z,C).
difficolta(X,Y,C):- arma(Y), debolezza(Z,Y), mostro(Z,W,C2), difficolta(X,W,C3), C is C3 + C2.

uccisioneConSpada(X,Y):- not(volante(X)), spada(Y), debolezza(X,Y).
uccisioneConSpada(X,Y):- not(volante(X)), spada(Y), debolezza(Z,Y), mostro(Z,W,_D), uccisioneConSpada(X,W).

uccisioneConArco(X,Y):- arco(Y), debolezza(X,Y).
uccisioneConArco(X,Y):- arco(Y), debolezza(Z,Y), mostro(Z,W,_D), uccisioneConArco(X,W).

