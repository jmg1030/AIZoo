Neurons.pop = 601;
Neurons.b = ones(Neurons.pop,1);

Neurons.WX = rand(Neurons.pop,Neurons.pop) - rand(Neurons.pop,Neurons.pop);
Neurons.WY = rand(Neurons.pop,Neurons.pop) - rand(Neurons.pop,Neurons.pop);
Neurons.WZ = rand(Neurons.pop,Neurons.pop) - rand(Neurons.pop,Neurons.pop);

Data.x = Y1;
Data.y = Y2;

Neurons.a = 0.1;
imagesc(Neurons.WX)

%%
[Values] = AutoEncoder(Data,Neurons);

[KL] = KLDivergence(dS,size(Values.X),Values.X,Data.x);

imagesc(Values.X)

%%
figure
subplot(3,1,1)
imagesc(Values.X)
subplot(3,1,2)
imagesc(Values.Y)
subplot(3,1,3)
imagesc(Values.Z)
figure
imagesc(Data.x)