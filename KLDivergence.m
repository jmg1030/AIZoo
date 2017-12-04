function [KL] = KLDivergence(x,dx,Y1,Y2)

X  = length(x);

KL = zeros(1,X);

for n=1:X-1
    
KL(n+1) = KL(n) - (log(Y1(n)/Y2(n)).*Y1(n).*dx);

end
