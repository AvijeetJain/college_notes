% Parameters
t = 0:0.0001:0.1;        % Time vector
fc = 1000;               % Carrier frequency (Hz)
fm = 50;                 % Modulation frequency (Hz)
Ac = 1;                  % Carrier amplitude
Am = 0.5;                % Modulation amplitude

% Modulation and Carrier signals
m_t = Am * sin(2 * pi * fm * t);  % Modulation signal
c_t = Ac * sin(2 * pi * fc * t);  % Carrier signal

% Modulated signal (AM)
s_t = (1 + m_t) .* c_t;

% Demodulation using envelope detection
s_t_envelope = abs(s_t) - Ac;  % Subtracting Ac to remove DC offset

% Plotting
figure;

% Modulation and Carrier signals
subplot(2,1,1);
plot(t, m_t, 'b', t, c_t, 'r');
title('Modulation (Blue) and Carrier (Red)');
xlabel('Time (s)');
ylabel('Amplitude');
legend('Modulation', 'Carrier');
grid on;

% Modulated signal
subplot(2,1,2);
plot(t, s_t, 'g');
title('Modulated Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
