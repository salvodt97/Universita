


%% assegnamento autovalori con reazione dallo stato mediante forma di Ackermann calcolata manualmente
g=[zeros(1,n-1) 1]*inv(Mr);
sigmaDes=[1 -eig_cl_des(1)];
for i=2:n
sigmaDes=conv(sigmaDes,[1 -eig_cl_des(i)]); % autovalori in -1(double), -3 
end
pADes=zeros(n);
for i=1:n+1
    pADes=pADes+A^(n-i+1)*sigmaDes(i);
end
Kacker1=-g*pADes; % formula di Ackermann esplicita

%% formula di Ackermann calcolata con il comando matlab

Kacker=-acker(A,B,eig_cl_des); 

A_cl=A+B*Kacker;
% check sul risultato
autoval_cl=eig(A_cl)
open('progStateFeedbackSim.slx')
sim('progStateFeedbackSim.slx')






