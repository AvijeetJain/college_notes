% Parameters
fc = 100;          % Carrier frequency (Hz)
fm = 10;            % Modulating frequency (Hz)
fs = 10*fc;         % Sampling frequency (Hz)
T = 1/fs;           % Sampling period
t = 0:T:1-T;        % Time vector

% Modulating signal (Sinusoidal)
m = sin(2*pi*fm*t);

% Carrier signal (Sinusoidal)
c = sin(2*pi*fc*t);

% Phase modulation
beta = 0.5;  % Modulation index (adjust as needed)
s_pm = c .* cos(2*pi*fm*t + beta*m);

% Plotting
figure;

% Modulating signal
subplot(3,1,1);
plot(t, m);
title('Modulating Signal');
xlabel('Time (s)');
ylabel('Amplitude');

% Carrier signal
subplot(3,1,2);
plot(t, c);
title('Carrier Signal');
xlabel('Time (s)');
ylabel('Amplitude');

% Phase modulated signal
subplot(3,1,3);
plot(t, s_pm);
title('Phase Modulated Signal');
xlabel('Time (s)');
ylabel('Amplitude');

% Display plots
grid on;
