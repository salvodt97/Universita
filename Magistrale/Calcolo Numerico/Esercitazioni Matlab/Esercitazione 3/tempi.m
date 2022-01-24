function [t1,t2] = tempi(A)
%UNTITLED6 Summary of this function goes here
% tic
% [L,D]=ldl(A);
% t1=toc;
% 
% tic
% [L,U]=lu(A);
% t2=toc;
%Così calcolo quanto tempo ci mette ua funzione; confronto quindi lu e ldl
%su una atrice simmetrica e mi aspetto che ldl ci mette meno tempo. Un solo
%risultato, un solo tempo, potremme essere poco preciso:

%timeit(@() function_da_provare());
%Si usa quindi timeit che esegue una funzione più volte ed esegue la media
%dei tempiper avere un risultato più accurato
t1=timeit(@()ldl(A));
t2=timeit(@()lu(A));
end

