% Parameters
num_trials = 1000; % Number of trials
SNR_dB = linspace(-10, 20, 50); % SNR range in dB
SNR = 10.^(SNR_dB/10); % Convert dB to linear scale
noise_power = 1; % Noise power
desired_rate = 1; % Desired data rate (bits/s/Hz)

% Initialize array for outage event count
outage_count = zeros(size(SNR));

x = randn(1, num_trials);
y = randn(1, num_trials);

% Generate Rayleigh channel
h = sqrt(1/2) * x + 1i * 1j;

for i = 1:length(SNR)
    % Calculate transmit power levels for each SNR
    P_t = SNR(i) * noise_power;
    
    % Calculate received SNR
    received_SNR = abs(h).^2 .* P_t / noise_power;
    
    % Calculate achievable SNR
    achievable_SNR = log2(1 + received_SNR);
    
    % Outage events for each SNR
    outage_count(i) = sum(achievable_SNR < desired_rate);
end

% Compute outage probability for each SNR level
outage_probability = outage_count / num_trials;

% Visualize transmit power vs outage probability
figure;
plot(SNR_dB, outage_probability, 'LineWidth', 2);
xlabel('Transmit Power (dB)');
ylabel('Outage Probability');
title('Wireless Outage Probability Estimation');
grid on;