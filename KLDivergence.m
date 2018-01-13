function [KL] = KLDivergence(dS,D,P,Q)

KL = zeros(D(1),D(2));

for m=1:D(1)
for n=1:D(2)

KL(m,n) = KL(m,n) - log(P(m,n)/Q(m,n)).*P(m,n).*dS;

end
end