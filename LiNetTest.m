Neurons.pop = 20;

TimeParams.time = 100;
TimeParams.dt   = 0.01;

Neurons.b = zeros(Neurons.pop,T);
Neurons.b(:,1) = 1;

Neurons.W = rand(Neurons.pop,Neurons.pop) - rand(Neurons.pop,Neurons.pop);

Neurons.W(Neurons.W < 0) = -1/Neurons.pop;
Neurons.W(Neurons.W > 0) = 1/Neurons.pop;
% Neurons.W(1,1) = -1;
% Neurons.W(1,2) = -1;
% Neurons.W(2,1) = 1;
% Neurons.W(2,2) = 1;

dt   = TimeParams.dt;
time = TimeParams.time;

t = 0:dt:time; 
T = length(t);

pop = Neurons.pop;

tau = Neurons.tau;

W = Neurons.W;
b = Neurons.b;

x = zeros(Neurons.pop,T);
X = Neurons.pop;
y = zeros(Neurons.pop,T);


for n=1:T-1

x(:,n+1) = x(:,n) + (- x(:,n) + x(:,n) + b(:,n)).*dt;
x(2:X-1,n+1) = x(2:X-1,n) + W*(x(2:X-1,n)+x(3:X,n)).*dt;

end

figure
plot(t,x)
figure
plot(t,y)