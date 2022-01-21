


eig_obs=[-2+4j -2-4j -20]; 

% check osservabilita'
O=obsv(A,C) ;
rankO=rank(O);
%% osservatore dello stato (assegnazione autovalori di errore di stima)
Kobs=acker(A',C',eig_obs); 
G=Kobs';
A_obs=A-G*C;
% check sul risultato
autoval_obs=eig(A_obs)

open('progStateFeedbackIntegralActObsSim.slx')
sim('progStateFeedbackIntegralActObsSim')








