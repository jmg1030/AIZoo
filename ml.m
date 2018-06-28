close all

dt = 0.1;
t = 0:dt:10;
T = length(t);

x = exp(-(t'-5).^2);
w1 = rand(T,1);
w2 = rand(T,1);
w3 = rand(T,1);

b1 = rand(T,1);
b2 = rand(T,1);
b3 = rand(T,1);

y1 = w1.*x+b1;
y2 = w2.*y1+b3;
y3 = w3.*y2+b3;

yhat = exp(-((t'-5)./5).^2);

L = (1/2).*sum((y3 - yhat).^2);
a = 1e-4;

%%

f = @(W,x,b) W.*x+b;
L = @(W,x,b,y) (1/2)*(W.*x + b - y).^2;
Lw = @(W,x,b,y) x.*(W.*x+b-y);
Lb = @(W,x,b,y) W.*x+b-y;

%%

I = 10000;
C = zeros(1,I);

for iter=1:I

    dW1 = -a.*Lw(L(L(w1,y1,b1,yhat),y2,b2,yhat),y3,b3,yhat).*Lw(L(w1,y1,b1,yhat),y2,b2,yhat).*Lw(w1,y1,b1,yhat);
    dW2 = -a.*Lw(L(w2,y2,b2,yhat),y3,b3,yhat).*Lw(w2,y2,b2,yhat);
    dW3 = -a.*Lw(w3,y3,b3,yhat);

    db1 = -a.*Lb(L(L(w1,y1,b1,yhat),y2,b2,yhat),y3,b3,yhat).*Lb(L(w1,y1,b1,yhat),y2,b2,yhat).*Lb(w1,y1,b1,yhat);
    db2 = -a.*Lb(L(w2,y2,b2,yhat),y3,b3,yhat).*Lb(w2,y2,b2,yhat);
    db3 = -a.*Lb(w3,y3,b3,yhat);

    w1  = w1  + dW1;
    w2  = w2  + dW2;
    w3  = w3  + dW3;
    
    b1  = b1  + db1;
    b2  = b2  + db2;
    b3  = b3  + db3;

    y1 = w1.*x+b1;
    y2 = w2.*y1+b3;
    y3 = w3.*y2+b3;

    C(iter) = (1/2).*sum((y3 - yhat).^2);
    
end

figure
plot(C)

%%

figure
subplot(3,1,1)
plot(t,x)
xlabel('Time (ms)');ylabel('Probability');title('Probability P(\theta)')
subplot(3,1,2)
plot(t,yhat)
xlabel('Time (ms)');ylabel('Probability');title('Actual Probability P(X)')
subplot(3,1,3)
plot(t,y3)
xlabel('Time (ms)');ylabel('Probability');title('Predicted Probability P3(X)')

%%
figure
subplot(3,1,1)
plot(t,y1)
xlabel('Time (ms)');ylabel('Probability');title('Predicted Probability P1(X)')
subplot(3,1,2)
plot(t,y2)
xlabel('Time (ms)');ylabel('Probability');title('Predicted Probability P2(X)')
subplot(3,1,3)
plot(t,y3)
xlabel('Time (ms)');ylabel('Probability');title('Predicted Probability P3(X)')

figure
subplot(2,1,1)
plot(t,w1)
xlabel('Time (ms)');ylabel('Weight');title('Weight of W for Wx + b (for P(X|\theta))')
subplot(2,1,2)
plot(t,b1)
xlabel('Time (ms)');ylabel('Bias');title('Bias of b for Wx + b (for P(X|\theta))')

figure
subplot(2,1,1)
plot(t,w2)
xlabel('Time (ms)');ylabel('Weight');title('Weight of W for Wx + b (for P(X|\theta))')
subplot(2,1,2)
plot(t,b2)
xlabel('Time (ms)');ylabel('Bias');title('Bias of b for Wx + b (for P(X|\theta))')

figure
subplot(2,1,1)
plot(t,w3)
xlabel('Time (ms)');ylabel('Weight');title('Weight of W for Wx + b (for P(X|\theta))')
subplot(2,1,2)
plot(t,b3)
xlabel('Time (ms)');ylabel('Bias');title('Bias of b for Wx + b (for P(X|\theta))')

figure
plot(t,w3.*(w2.*(w1.*t'+b1)+b2)+b3)
xlabel('Time (ms)');ylabel('Probability');title('P(X|\theta)')