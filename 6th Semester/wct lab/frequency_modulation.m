t = 0:0.001:1; %upto 1000 samples
vm = 5;
vc = 5;
fM = 8;
fc = 100;
m = 10;
msg = vm*sin(2*pi*fM*t);
subplot(3,1,1); %plotting message signal
plot(t,msg);
xlabel('Time');
ylabel('Amplitude');
title('Message ');

carrier = vc*sin(2*pi*fc*t);
subplot(3,1,2); %plotting carrier signal
plot(t,carrier);
xlabel('Time');
ylabel('Amplitude');
title('Carrier Signal');

y = vc*sin(2*pi*fc*t+m.*cos(2*pi*fM*t));
subplot(3,1,3);%plotting FM (Frequency Modulated) signal
plot(t,y);
xlabel('Time');
ylabel('Amplitude');
title('FM Signal');