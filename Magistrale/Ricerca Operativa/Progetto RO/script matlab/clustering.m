function [] = clustering(X,i)
[idx,C]=kmeans(X,i);
gscatter(X(:,1), X(:,2), idx)
hold on
plot(C(:,1), C(:,2), 'kx', 'Markersize', 15)
end

