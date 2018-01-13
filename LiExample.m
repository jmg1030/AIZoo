Neurons.pop = 2;

TimeParams.time = 10;
TimeParams.dt   = 0.01;

T = length(0:TimeParams.dt:TimeParams.time);

Neurons.b = ones(Neurons.pop,T);
%Neurons.b(1,1) = 1;

K = 100;

Neurons.W = abs(ones(Neurons.pop,Neurons.pop));

Neurons.tau = ones(Neurons.pop,1);

[Values] = LiNet(TimeParams,Neurons);

figure
plot(Values.t,Values.x)
%%
% figure
% subplot(2,1,1)
% plot(Values.t,Values.x,'k');
% subplot(2,1,2)
% plot(Values.t,Values.f,'r');

% figure
% subplot(2,1,1);
% plot(Values.t,Values.x(1:Neurons.Epop,:),'b');
% subplot(2,1,2);
% plot(Values.t,Values.x(Neurons.Epop+1:pop,:),'r');
% 
figure
imagesc(Values.x)



