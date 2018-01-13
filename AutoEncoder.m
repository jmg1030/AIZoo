function [Values] = AutoEncoder(Data,Neurons);

x = Data.x;
y = Data.y;

pop = Neurons.pop;

WX = Neurons.WX;
WY = Neurons.WY;
WZ = Neurons.WZ;

b = Neurons.b;
a = Neurons.a;

DX = size(WX);
DY = size(WY);
DZ = size(WZ);

%%

X = 1./(1 + exp(-(WX*x + b)));
%Y = 1./(1 + exp(-(WY*X + b)));
%Z = 1./(1 + exp(-(WZ*Y + b)));

WX = GradientDescent(a,WX,DX,X,y);
%WY = GradientDescent(a,WY,DY,Y,Z);
%WZ = GradientDescent(a,WZ,DZ,Z,y);

Data.WX = WX;

Values.X = X;
%Values.Y = Y;
%Values.Z = Z;