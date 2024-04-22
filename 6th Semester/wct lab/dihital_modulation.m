% Binary message
message = [1 0 1 1 0 1 0 0];

% Parameters
fc = 10; % Carrier frequency for ASK and FSK
fs = 1000; % Sampling frequency
Tb = 1; % Bit duration
t = 0:1/fs:Tb-1/fs; % Time vector for one bit duration

% Carrier signals
carrier_ASK = cos(2 * pi * fc * t);
carrier_FSK_1 = cos(2 * pi * fc * t);
carrier_FSK_2 = cos(2 * pi * 2*fc * t);
carrier_PSK_1 = cos(2 * pi * fc * t);
carrier_PSK_2 = cos(2 * pi * fc * t + pi/2); % 90 degrees phase shift

% Initialize modulation signals
ASK_signal = [];
FSK_signal = [];
PSK_signal = [];

% Modulation
for bit = message
    % ASK Modulation
    if bit == 1
        ASK_signal = [ASK_signal, carrier_ASK];
    else
        ASK_signal = [ASK_signal, zeros(size(carrier_ASK))];
    end
    
    % FSK Modulation
    if bit == 1
        FSK_signal = [FSK_signal, carrier_FSK_1];
    else
        FSK_signal = [FSK_signal, carrier_FSK_2];
    end
    
    % PSK Modulation
    if bit == 1
        PSK_signal = [PSK_signal, carrier_PSK_1];
    else
        PSK_signal = [PSK_signal, carrier_PSK_2];
    end
end

% Time vector for entire message
t_total = 0:1/fs:(length(message) * Tb - 1/fs);

% Plot modulated signals
figure;

subplot(3,1,1);
plot(t_total, ASK_signal);
title('ASK Modulated Signal');
xlabel('Time (s)');
ylabel('Amplitude');
ylim([-1.5 1.5]);
grid on;

subplot(3,1,2);
plot(t_total, FSK_signal);
title('FSK Modulated Signal');
xlabel('Time (s)');
ylabel('Amplitude');
ylim([-1.5 1.5]);
grid on;

subplot(3,1,3);
plot(t_total, PSK_signal);
title('PSK Modulated Signal');
xlabel('Time (s)');
ylabel('Amplitude');
ylim([-1.5 1.5]);
grid on;
