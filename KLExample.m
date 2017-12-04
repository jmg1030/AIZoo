dx = 0.01;
x  = 0:dx:10;

Y1 = exp(-x.^2);
Y2 = exp(-x);

Z = Y1.*Y2;

X  = length(x);

[KL] = KLDivergence(x,dx,Y1,Z);

plot(x,KL)
