dx = 0.01;
dy = 0.01;
dS = dx*dy;

[x,y] = meshgrid(-3:dx:3,-3:dy:3);

p = 0.5;

Y1 = exp(- x.^2 -  y.^2);
Y2 = exp(- x.^2 -  y.^2 - 2.*p.*x.*y);
%Y2 = exp(- x.*y);

%imagesc(Y2)
[E] = Entropy(dS,size(x),Y2);
imagesc(E)
colorbar
