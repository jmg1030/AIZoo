function [E] = Entropy(dx,D,X)

E = zeros(D(1),D(2));

for m=1:D(1)
for n=1:D(2)

E(m,n) = E(m,n) - log(X(m,n)).*X(m,n).*dx;

end
end