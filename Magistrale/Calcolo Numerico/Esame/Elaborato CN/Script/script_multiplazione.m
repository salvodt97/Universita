%Questo script ha lo scopo di simulare la trasmissione di 2 segnai
%gaussiani mediante due portanti in quadratura, un seno e un coseno.

clc
clear all
close all

%Parametri utili da usare
N=1000;                  %n sarebbe un mixed radix (2^4*5*3)
dt=1/(N-1);              %passo di dicretizzazione
t=(-N:N-1)' *dt;         %intervallo temporale
fo=100;                  %frequenza delle sinusoidi usate per modulare
Fs=1/dt;                 %frequenza di campinamento
f=(-N:N-1)' *Fs/(2*N);   %multipli di frequenza fondamentale

%Defininiamo ora il primo segnale da modolare lungo la portante coseno
disp('Segnale x1(t) da modulare in coseno')
xx1=(gausswin(2*N+1,20));                    %Come paraetri indichiamo l'intervallo di definizione e la deviazione standard
x1=xx1(1:2*N);
figure(1)
clf 
subplot(211);
plot(t,x1)
axis([-dt*2*N/10 dt*2*N/10 -0.5 1.5])        %Scalatura degli assi per visualizzare cosa ci serve
grid on
xlabel('t (s)')
title('x1(t)')

subplot(212);
X1=fft(fftshift(x1));                        %ffshift ci sposta la frequenza 0 al centro dello spettro
plot(f, fftshift(real(X1))*dt)               %specifico real in quanto X1 ha solo la parte reale essendo il segnale reale
axis([-3*fo 3*fo -100*dt 300*dt])
grid on
xlabel('f (Hz)')
title('X1(f)')

disp('Premere un tasto per visualizzare il segnale x2(t) da modulare in seno')
pause

%Defininiamo ora il secondo segnale da modolare lungo la portante seno
xx2=.5*(gausswin(2*N+1,20));
x2=xx2(1:2*N);
figure(2)
clf
subplot(211)
plot(t,x2)
grid on
axis([-dt*2*N/10 dt*2*N/10 -0.5 1.5])
xlabel('t (s)')
title('x2(t)')

subplot(212);
X2=fft(fftshift(x2));
plot(f,fftshift(real(X2))*dt)
grid on
axis([-3*fo 3*fo -100*dt 300*dt])
xlabel('f (Hz)')
title(' X2(f)')


disp('Premere un tasto per visualizzare il segnale x1(t) modulato in coseno: y(1)=x1(t)*cos(2*pi*t*fo)')
pause

%Defininiamo ora y1(t), ovvero x1(t) modulato in coseno
y1=x1.*cos(2*pi*t*fo);                   %Per modulare la funzione in coseno la moltiplichiamo per il coseno
figure(3)
subplot(211)
hold on
plot(t,y1)
axis([-dt*2*N/10 dt*2*N/10 -1.5 1.5])
grid on
xlabel('t (s)')
title('y1(t)')

subplot(212)
hold on
Y1=fft(fftshift(y1));
plot(f,fftshift(real(Y1))*dt)
axis([-3*fo 3*fo -100*dt 200*dt])
grid on
xlabel('f (Hz)')
title('Y1(f) (reale)')



disp('Premere un tasto per visualizzare il segnale x2(t) modulato in seno: y(2)=x2(t)*sin(2*pi*t*fo)')
pause

%Defininiamo ora y2(t), ovvero x2(t) modulato in seno
y2=x2.*sin(2*pi*t*fo);          %Per modulare la funzione in seno la moltiplichiamo per il seno
figure(4)
subplot(211)
plot(t,y2)
grid on
xlabel('t (s)')
title('y2(t)')
axis([-dt*2*N/10 dt*2*N/10 -1.5 1.5])

subplot(212)
Y2=fft(fftshift(y2));
plot(f,fftshift(imag(Y2))*dt)   %Mostriamo la parte immaginaria in quanto Y2(f) è solo immaginaria: questo perchè y2(t) si ottiene mediante prodoto con un seno
axis([-3*fo 3*fo -100*dt 200*dt])
grid on
xlabel('f (Hz)')
title('Y2(f) (immaginaria)')

disp('Premere un tasto per visualizzare entrambi i segnali y1 e y2')
pause

%Facciamo ora visualizzare insieme i 2 segnali da sommare
figure(3)
subplot(211)
plot(t,y2, 'r')
grid on
xlabel('t (s)')
title('y1(t) e y2(t)')
axis([-dt*2*N/10 dt*2*N/10 -1.5 1.5])

subplot(212)
plot(f,fftshift(imag(Y2))*dt, 'r')   %Mostriamo la parte immaginaria in quanto Y2(f) è solo immaginaria: questo perchè y2(t) si ottiene mediante prodoto con un seno
axis([-3*fo 3*fo -100*dt 200*dt])
grid on
xlabel('f (Hz)')
title('Y1(f) (reale) e Y2(f) (immaginaria)')

disp('Premere un tasto per visualizzare il segnale trasmesso, ovvero la somma  z(t)=y1(t)+y2(t)')
pause

%Definiamo ora il segnale da trasmettere z(t)=y1(t)+y2(t)
z=y1+y2;
figure(5)
plot(t,z)
grid on
xlabel('t (s)')
title('z(t) = y1(t)+y2(t)')
axis([-dt*2*N/10 dt*2*N/10 -1.5 1.5])

disp('Premere un tasto per visualizzare la trasformata di Fourier (complessa) di z(t)')
pause

%Codice per visualizzare Z(f), che essendo complessa ha una parte reale e una
%parte immaginaria
Z=fft(fftshift(z));
figure(6)
subplot(211)
plot(f,fftshift(real(Z))*dt)
grid on
axis([-3*fo 3*fo -100*dt 200*dt])
xlabel('f (HZ)')
title('Z(f) parte reale')

subplot(212)
plot(f,fftshift(imag(Z))*dt)
grid on
axis([-3*fo 3*fo -100*dt 200*dt])
xlabel('f (Hz)')
title('Z(f) parte immaginaria')

disp('Premere un tasto per visualizzare z(t) demodulato in coseno: z1(t)=z(t)*cos(2*pi*t*fo)')
pause

%Codice per visualizzare z(t) demodulato in coseno
z1=z.*2.*cos(2*pi*t*fo);
figure(7)
plot(t,z1);
grid on
xlabel('t (s)')
title('z1(t)')
axis([-dt*2*N/10 dt*2*N/10 -1.5 2.5])



disp('Premere un tasto per visualizzare Z1(f) complessa')
pause

%Codice per visualizzare Z1(f)
figure(8)
Z1=fft(fftshift(z1));
subplot(211)
plot(f,fftshift(real(Z1))*dt)
axis([-3*fo 3*fo -100*dt 300*dt])
grid on
xlabel('f (Hz)')
title('Parte reale di  Z1(f)')
hold on
subplot(212)
plot(f,fftshift(imag(Z1))*dt)
axis([-3*fo 3*fo -150*dt 300*dt])
grid on
xlabel('f (Hz)')
title('Parte immaginaria di Z1(f)')

disp('Premere un tasto per visualizzare z(t) demodulato in seno: z2(t)=z(t)*sen(2*pi*t*fo)')
pause

%Codice per visualizzare z2(t)
figure(9)
z2=z.*2.*sin(2*pi*t*fo);
plot(t,z2);
grid on
xlabel('t (s)')
title('z2(t)')
axis([-dt*2*N/10 dt*2*N/10 -1.5 2.5])

disp('Premere un tasto per visualizzare Z2(f) complessa')
pause

%Codice per visualizzare Z2(f) complessa
figure(10)
Z2=fft(fftshift(z2));
subplot(211)
plot(f,fftshift(real(Z2))*dt)
grid on
axis([-3*fo 3*fo -100*dt 300*dt])
xlabel('f (Hz)')
title('Parte reale di Z2(f)')
subplot(212)
plot(f,fftshift(imag(Z2)*dt))
grid on
title('Parte immaginaria di Z2(f)')
axis([-3*fo 3*fo -150*dt 300*dt])
xlabel('f (Hz)')

disp('Premere un tasto per visualizzare un confronto tra x1(t) e z1(t)')
pause

%Codice per confrontare x1(t) e z1(t)
figure(11)
plot(t,x1, 'r')
hold on
plot(t,z1,'b') 
hold on
axis([-dt*2*N/10 dt*2*N/10 -1.5 2.5])        
grid on
xlabel('t (s)')
title('x1(t) e z1(t)')
legend('x1(t)', 'z1(t)')

disp('Premere un tasto per visualizzare un confronto tra X1(f) e Z1(f)')
pause

%Codice per visualizzare X1(f) e Z1(f)
figure(12)
plot(f, fftshift(real(X1))*dt, 'r') 
hold on
plot(f,fftshift(real(Z1))*dt, 'b')
hold on
axis([-3*fo 3*fo -100*dt 300*dt])
grid on
xlabel('f (Hz)')
title('X1(f) e Z1(f)')
legend('X1(f)', 'Z1(f)')

disp('Premere un tasto per visualizzare un confronto tra x2(t) e z2(t)')
pause

%Codice per confrontare x2(t) e z2(t)
figure(13)
plot(t,x2, 'r')
hold on
plot(t,z2,'b') 
hold on
axis([-dt*2*N/10 dt*2*N/10 -1.5 2.5])        
grid on
xlabel('t (s)')
title('x2(t) e z2(t)')
legend('x2(t)', 'z2(t)')

disp('Premere un tasto per visualizzare un confronto tra X2(f) e Z2(f)')
pause

%Codice per confrontare X2(f) e Z2(f)
figure(14)
plot(f, fftshift(real(X2))*dt, 'r')  
hold on
plot(f,fftshift(real(Z2))*dt, 'b')
hold on
axis([-3*fo 3*fo -100*dt 300*dt])
grid on
xlabel('f (Hz)')
title('X2(f) e Z2(f)')
legend('X2(f)', 'Z2(f)')

