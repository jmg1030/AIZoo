function [Values] = CortexNet(TimeParams,Neurons);

dt   = TimeParams.dt;
time = TimeParams.time;

t = 0:dt:time; 
T = length(t);

Epop = Neurons.Epop;
Ipop = Neurons.Ipop;

pop = Epop + Ipop;

tau = Neurons.tau;

W = Neurons.W;

b = Neurons.b;

x = zeros(pop,T);
f = zeros(pop,T);

%%

for n=1:T-1

x(:,n+1) = x(:,n) + atan(W*x(:,n) + b(:,n)).*dt;
f(:,n+1) = sum(x(:,n+1))./pop;

end

Values.t = t;
Values.x = x;