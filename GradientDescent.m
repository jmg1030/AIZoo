function [W] = GradientDescent(a,W,D,x,y)

for i=1:D(1)
for j=1:D(2)

W(i,j) = W(i,j) - a.*(-(y(i,j) - 1./(1+exp(-x(i,j)))).*(1./1+x(i,j).^2));

end
end