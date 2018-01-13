function [J] = CostFunction(W,b,x,y)

D = size(W);

%J = zeros(size(W),size(b));

%for m=1:size(W)
%for n=1:size(b)

WSum = 0;

for i=1:D(1)
for j=1:D(2)

WSum = WSum + W(i,j);

end
end

J = sum(sqrt((W*x).^2 - (y).^2)./2) + WSum;

%end
%end
