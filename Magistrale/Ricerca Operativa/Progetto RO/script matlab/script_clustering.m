%Punti da clusterizzare
X= [25 25; 105 75; 40 120; 140 130; 195 25; 230 240; 195 90; 230 165; 185 245; 135 40; 80 175; 
    35 220; 175 170; 20 160; 130 245];
[righe, colonne]=size(X);
i=input('Inserire il numero di cluster: ');
stampa=['Il numero di cluster deve essere compreso tra 0 e ', num2str(righe)];
while(i<=0 || i>15)
    disp(stampa)
    i=input('Inserire il numero di cluster: ');
end
clustering(X,i);