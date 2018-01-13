function [Values] = LiNet(TimeParams,Neurons);

dt   = TimeParams.dt;
time = TimeParams.time;

t = 0:dt:time; 
T = length(t);

pop = Neurons.pop;

tau = Neurons.tau;

W = Neurons.W;
b = Neurons.b;

x = zeros(pop,T);
y = zeros(pop,T);

%%

for n=1:T-1

x(:,n+1) = x(:,n) + (- x(:,n) + y(:,n) + b(:,n)).*dt./tau;
y(:,n+1) = y(:,n) + W*(x(:,n)+y(:,n)).*dt;

end

Values.t = t;
Values.x = x;