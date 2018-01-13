dt = 0.01;
tend = 1000;
t = 0:dt:tend;
T = length(t);

N = 100;
tau = 10;

K = 10;

W = zeros(N);
We = 10.*(rand(N,N./2) < K./N);
Wi = -10.*(rand(N,N./2) < K./N);

W(:,1:50)   = We;
W(:,51:100) = Wi;

x = zeros(N,T);
s = zeros(N,T);

I = zeros(N,T);
I(:,1) = 10.*ones(N,1);

for n = 1:T-1
    
dx = - x(:,n) + s(:,n);

x(:,n+1) = x(:,n) + dx.*dt./tau;
s(:,n+1) = 1./(1+exp(-W*x(:,n) + I(:,n)));

end

plot(t,x)