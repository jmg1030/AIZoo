function [Values] = CortexNet(TimeParams,Neurons);

dt   = TimeParams.dt;
time = TimeParams.time;

t = 0:dt:time; 
T = length(t);

Epop = Neurons.Epop;
Ipop = Neurons.Ipop;

pop = Epop + Ipop;

tau = Neurons.tau;
syn = Neurons.syn;

W = Neurons.W;
A = Neurons.A;

I = Neurons.I;

x = zeros(pop,T);
y = zeros(pop,T);
r = zeros(pop,T);
f = zeros(pop,T);

%%

for n=1:T-1

x(:,n+1) = x(:,n) + (- x(:,n) + W*r(:,n) + I(:,n)).*dt./tau;
y(:,n+1) = y(:,n) + x(:,n).*dt.*A;
r(:,n+1) = 1./(1 + exp(-x(:,n+1).*syn));

f(:,n+1) = sum(x(:,n+1))./pop;

end

Values.t = t;
Values.x = x;
Values.r = r;
Values.f = f;