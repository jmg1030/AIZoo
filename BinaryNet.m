%Time
dt      = 0.01;
tend    = 100;
t       = 0:dt:tend;
T       = length(t);

%Neurons
pop = 100;
I   = 0.5.*ones(pop,T);
K = 10;
W = rand(pop)<=K./pop;
W(diag(diag(true(size(W)))))=0;

%Variables
x = zeros(pop,T);
s = zeros(pop,T);
randnum = zeros(pop,T);

spikes = nan(pop.*(tend).*150,2);
spikecounter = 0;

s(:,1) = rand(pop,1);

%Simulation
for n = 1:T-1

x(:,n) = W*s(:,n) + I(:,n);

randnum(:,n) = exprnd(50,[pop,1]);
%randnum(:,n) = exprnd(50);

if any(x(:,n) > randnum(:,n))

stateneurons = find(x(:,n) > randnum(:,n));
s(stateneurons,n+1) = 1;

numspikers = length(stateneurons);

spikes(spikecounter+1:spikecounter+numspikers,:) = [t(n).*ones(numspikers,1),stateneurons];
spikecounter = spikecounter+numspikers;

end

end

figure
subplot(2,1,1)
imagesc(x)
subplot(2,1,2)
scatter(spikes(1),spikes(2))

%%
p = linspace(0,15,10);
diffmat = diff(SpikeTimes,1,2);

loopval = size(SpikeTimes);

isiTimes = [];

for m = 1:loopval(1)-1
    
isiTimes = [isiTimes diffmat(m,:)];

end
    
[q,r] = hist(isiTimes,p);
plot(r,q)