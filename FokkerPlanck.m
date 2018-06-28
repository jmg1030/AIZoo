dt = 0.01;
dx = 0.1;

s = dt/dx;

tBounds = [0,50];
xBounds = [-55,-40];

t = tBounds(1):dt:tBounds(2);
x = xBounds(1):dx:xBounds(2);

T = length(t);
X = length(x);

v = zeros(X,T);
X_t = zeros(1,T);

id = find(x==-55);

v(:,1) = 10.*exp(-(x+55).^2/100);
v(102:length(v(
%v(id,1) = 10;

I = 500;

tau = C(1)/g_L(1);
sigma = 1./tau;
theta = 1/tau;
h = E_L(1) + I/g_L(1);

for n = 1:T-1

v(2:X-1,n+1) = v(2:X-1,n) + (theta.*(x(2:X-1)' - h).*(v(2:X-1,n)-v(1:X-2,n))).*(dt/(dx)) + (sigma.^2).*(v(3:X,n) + v(1:X-2,n) - 2.*v(2:X-1,n)).*(dt/(dx^2));
v(1,n+1) = v(1,n+1) + v(101,n+1);
v(101,n+1) = 0;

end

figure
imagesc(flipud(v'))
%colorbar
%hold on
%plot(t,X_t)