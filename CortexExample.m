Neurons.Ipop = 50;
Neurons.Epop = 50;

Neurons.A = 0;

pop = Neurons.Ipop + Neurons.Epop;

TimeParams.time = 100;
TimeParams.dt   = 0.01;

T = length(0:TimeParams.dt:TimeParams.time);

Neurons.I = ones(pop,T);
Neurons.I(1,1) = 1;

K = 10;

Neurons.W = (rand(pop) - rand(pop));

Neurons.tau = ones(pop,1);
Neurons.syn = 1000.*ones(pop,1);

[Values] = CortexNet(TimeParams,Neurons);

%%
figure
subplot(2,1,1)
plot(Values.t,Values.x,'k');
subplot(2,1,2)
plot(Values.t,Values.f,'r');

figure
subplot(2,1,1);
plot(Values.t,Values.x(1:Neurons.Epop,:),'b');
subplot(2,1,2);
plot(Values.t,Values.x(Neurons.Epop+1:pop,:),'r');

figure
imagesc(Values.x)



