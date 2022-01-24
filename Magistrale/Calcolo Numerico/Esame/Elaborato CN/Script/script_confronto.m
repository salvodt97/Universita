clf
close all
clear all

DT=0.1;         %passo di discretizzazione
N=32;           %numero di campioni
n=(0:N-1);      %vettore dei campioni

%Prima sequenza di campioni simmetrica rispetto a n=0
%Codice per mostrare la sequenza di campioni
figure(1)
clf
x=zeros(N,1);
x(1)=1/2;
x(2)=1/4;
x(N)=1/4;
stem(n,x,'filled');
grid on
xlabel('campioni nel tempo')
title('Prima sequenza di campioni da trasformare')
pause

%Codice per mostrare la DFT
figure(2)
clf
To=N*DT;
DF=1/To;        
X=fft(x);
subplot(211)
stem(DF*n,real(X))
grid on
title('DFT della sequenza x')
xlabel('f (Hz)')

%Codice per mostrare la trasformata continua
M=1000;
m=(0:M-1);
xx=zeros(M,1);
xx(1)=1/2;
xx(2)=1/4;
xx(M)=1/4;
TTo=M*DT;
df=1/TTo;
XX=fft(xx);
subplot(212)
plot(df*m,real(XX))
grid on
xlabel('f (Hz)')
title('Trasformata di Fourier continua della seuqnza x')
pause

%Confronto tra trasformata continua e discreta
figure (3)
clf
plot(df*m,real(XX))
grid on
xlabel('f (Hz)')
hold on
stem(DF*n,real(X),'r','filled')
title('Confronto tra trasfomrata continua e discreta')
legend('Trasformata continua', 'DFT', 'Location', 'north')
xlabel('f (Hz)')

disp('Premere un tasto per procedere con la seconda squenza di campioni')
pause


%Seconda sequenza di campioni
clf
close all
clear all

DT=0.1;
N=32;
n=(0:N-1);

%Codice per mostrare la sequenza di campioni
figure(4)
clf
x=zeros(N,1);
x(1)=1/2;
x(2)=-1/4;
x(N)=-1/4;
stem(n,x,'filled');
grid on
xlabel('campioni nel tempo')
title('Seconda sequenza di campioni da trasformare')

pause

%Codice per mostrare la DFT
figure(5)
clf
To=N*DT;
DF=1/To;
X=fft(x);
subplot(211)
stem(DF*n,real(X))
grid on
xlabel('f (Hz)')
title('DFT della seuqnza x')
%Codice per mostrare la trasfrmata continua
M=1000;
m=(0:M-1);
xx=zeros(M,1);
xx(1)=1/2;
xx(2)=-1/4;
xx(M)=-1/4;
TTo=M*DT;
df=1/TTo;
XX=fft(xx);
subplot(212)
plot(df*m,real(XX))
xlabel('f (Hz)')
title('Trasformata di Fourier continua della seuqnza x')
grid on

pause

%Codice per confrontare trasformata continua e discreta
figure(6)
clf
plot(df*m,real(XX))
xlabel('f (Hz)')
title('Trasformata di Fourier continua della seuqnza x')
grid on
hold on
stem(DF*n,real(X),'r','filled')
legend('Trasformata continua', 'DFT')
title('Confronto tra trasfomrata continua e discreta')

disp('Premere un tasto per procedere con la terza squenza di campioni')
pause

%Terza sequenza
clf
close all
clear all

DT=0.1;
N=32;
n=(0:N-1);

%Codice per mostrare la sequenza
figure(7)
clf
x=cos(2*pi*n/8);
stem(n,x,'filled');
grid on
xlabel('campioni nel tempo')
title('Terza sequenza da trasformare')

pause

%Codice per mostrare la parte reale e immagimaria della DFT
figure(8)
clf
To=N*DT;
DF=1/To;
X=fft(x);
subplot(211)
stem(DF*n,real(X))
hold on
grid on
xlabel('f (Hz)')
title('DFT parte reale')
subplot(212)
stem(DF*n,imag(X))
hold on
grid on
xlabel('h (Hz)')
title('DFT parte immaginaria')

pause

%Codice per mostrare parte reale e immainaria della trasformata continua
M=1000;
m=(0:M-1);
xx=zeros(M,1);
xx(1:N)=cos(2*pi*n/8);
TTo=M*DT;
df=1/TTo;
XX=fft(xx);
figure(9)
subplot(211)
plot(df*m,real(XX))
grid on
xlabel('f (Hz)')
title('Trasformata di Fourier continua (parte reale)')
subplot(212)
plot(df*m,imag(XX))
xlabel('f (Hz)')
grid on
xlabel('f (Hz)')
title('Trasformata di Fourier continua (parte immaginaria)')

pause

%Codice per confrontare parte reale della trasformata contnua e discreta
%e per confrontare parte immaginaria della trasformata continua e discreta
figure(8)
subplot(211)
plot(df*m,real(XX), 'r')
grid on
xlabel('f (Hz)')
title('Confronto tra le parti reali')
legend('Dft','Trasformata continua');
subplot(212)
plot(df*m,imag(XX), 'r')
grid on
xlabel('f (Hz)')
title('Confronto tra le parti immaginarie')
legend('Dft','Trasformata continua');

disp('Premere un tasto per procedere con la quarta squenza di campioni')
pause

%Quarta sequenza
clf
close all
clear all

DT=0.1;
N=32;
n=(0:N-1);

%Codice per mostrare la sequenza
figure(10)
clf
x=cos(2*pi*n/7);
stem(n,x,'filled');
grid on
xlabel('campioni nel tempo')
title('Quarta sequenza da trasformare')

pause

%Codice per mostrare la parte reale e immagimaria della DFT
figure(11)
clf
To=N*DT;
DF=1/To;
X=fft(x);
subplot(211)
stem(DF*n,real(X))
hold on
grid on
xlabel('f (Hz)')
title('DFT parte reale')
subplot(212)
stem(DF*n,imag(X))
hold on
grid on
xlabel('h (Hz)')
title('DFT parte immaginaria')

pause

%Codice per mostrare parte reale e immainaria della trasformata continua
M=1000;
m=(0:M-1);
xx=zeros(M,1);
xx(1:N)=cos(2*pi*n/8);
TTo=M*DT;
df=1/TTo;
XX=fft(xx);
figure(12)
subplot(211)
plot(df*m,real(XX))
grid on
xlabel('f (Hz)')
title('Trasformata di Fourier continua (parte reale)')
subplot(212)
plot(df*m,imag(XX))
xlabel('f (Hz)')
grid on
xlabel('f (Hz)')
title('Trasformata di Fourier continua (parte immaginaria)')

pause

%Codice per confrontare parte reale della trasformata contnua e discreta
%e per confrontare parte immaginaria della trasformata continua e discreta
figure(11)
subplot(211)
plot(df*m,real(XX), 'r')
grid on
xlabel('f (Hz)')
title('Confronto tra le parti reali')
legend('Dft','Trasformata continua');
subplot(212)
plot(df*m,imag(XX), 'r')
grid on
xlabel('f (Hz)')
title('Confronto tra le parti immaginarie')
legend('Dft','Trasformata continua');



