% Given parameters
d0 = 100;  % reference distance in meters
Pt_dBm = 0;  % transmit power in dBm
n = 4.4;  % pathloss exponent
mean_shadowing = 6.17;  % mean of shadowing effect in dB
BER = 1e-6;  % target bit error rate

% Convert dB to linear scale
Pt = 10^(Pt_dBm / 10);

% Function to calculate path loss in dB
path_loss = @(d) 10 * n * log10(d / d0);

% Function to calculate received power in dBm
received_power = @(d, shadowing) Pt - path_loss(d) - shadowing;

% Function to calculate SNR in dB
snr = @(d, N0) received_power(d, N0) - N0;

% Function to calculate outage probability
outage_probability = @(snr) 0.5 * erfc(sqrt(2 * 10^(snr / 10)));

% Distance range from 1 km to 5 km
distances = linspace(1000, 5000, 100);

% Noise power assuming AWGN channel (N0 = 0 dBm)
N0_dBm = 0;

% Generate shadowing effects for each distance
shadowing_effects = mean_shadowing * ones(size(distances));

% Calculate outage probability for each distance
outage_probabilities = zeros(size(distances));
for i = 1:length(distances)
    snr_dB = snr(distances(i), N0_dBm);
    outage_probabilities(i) = outage_probability(snr_dB);
end

% Plotting
figure;
plot(distances, outage_probabilities);
title('Outage Probability vs Distance');
xlabel('Distance (m)');
ylabel('Outage Probability');
grid on;
set(gca, 'YScale', 'log');