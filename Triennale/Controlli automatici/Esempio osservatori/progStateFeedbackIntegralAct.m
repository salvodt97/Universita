
%% aggiunta di un azione di controllo integrale sull'uscita per avere inseguimento perfetto

% definizione dell'ulteriore autovalore desiderato
eig_cl_des=[eig_cl_des -30];

% aggiunta dell'azione integrale tra le variabili di stato a cc
Amod=[A zeros(n,1); -C 0];
Bmod=[B;0];
Mrmod=ctrb(Amod,Bmod);
rankR=rank(Mrmod);

% formula di Ackermann
KackerMod=-acker(Amod,Bmod,eig_cl_des); 

% assegnamento autovalori con reazione dallo stato mediante forma di Ackermann calcolata manualmente
nMod=length(Amod);
g=[zeros(1,nMod-1) 1]*inv(Mrmod);
sigmaDes=[1 -eig_cl_des(1)];
for i=2:nMod
sigmaDes=conv(sigmaDes,[1 -eig_cl_des(i)]); % autovalori in -1(double), -3 
end
pADes=zeros(nMod);
for i=1:n+1
    pADes=pADes+Amod^(nMod-i+1)*sigmaDes(i);
end
KackerMod1=-g*pADes; % formula di Ackermann esplicita



A_cl=Amod+Bmod*KackerMod;
% check sul risultato
autoval_cl=eig(A_cl)
open('progStateFeedbackIntegralActSim.slx')
sim('progStateFeedbackIntegralActSim.slx')
