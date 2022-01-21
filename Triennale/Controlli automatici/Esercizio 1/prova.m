clear
close all

t=linspace(-pi,pi,20);  %così dico il primo punto, -pi, l'ultimo punto, pi, e tra i 2 punti l'intervallo(pi/10), è un vettore dei tempi
y1=sin(t);       

% figure
% plot(t,y1,'o-r','LineWidth',2);
% grid
% xlabel('tempo t (sec)', 'Fontsize', 12, 'FontWeight', 'bold')
% ylabel('seno(t)', 'Fontsize', 12, 'FontWeight', 'bold')
% 

%% "hold on"
% y2=cos(t);
% hold on
% plot(t,y2,'o-b','LineWidth',2);
% grid
% xlabel('tempo t (sec)', 'Fontsize', 12, 'FontWeight', 'bold')
% ylabel('f(t)', 'Fontsize', 12, 'FontWeight', 'bold')
% legend('seno(t)','coseno(t)','Location','northeast')
% 

%% "subplot"
y2=cos(t);
figure
subplot(2,1,1)
plot(t,y1,'o-r','LineWidth',2);
grid
xlabel('tempo t (sec)', 'Fontsize', 12, 'FontWeight', 'bold')
ylabel('seno(t)', 'Fontsize', 12, 'FontWeight', 'bold')
subplot(2,1,2)
grid
plot(t,y2,'o-y','LineWidth',2);
xlabel('tempo t (sec)', 'Fontsize', 12, 'FontWeight', 'bold')
ylabel('coseno(t)', 'Fontsize', 12, 'FontWeight', 'bold')

%% semilogx, semilogy, loglog
clear
close all
x=1:0.01:10;
y=10.^(-x);

% figure
% plot(x,y)
% xlabel('x', 'Fontsize', 12, 'FontWeight', 'bold')
% ylabel('f(x)', 'Fontsize', 12, 'FontWeight', 'bold')

figure
semilogx(x,y)
xlabel('x', 'Fontsize', 12, 'FontWeight', 'bold')
ylabel('f(x)', 'Fontsize', 12, 'FontWeight', 'bold')

