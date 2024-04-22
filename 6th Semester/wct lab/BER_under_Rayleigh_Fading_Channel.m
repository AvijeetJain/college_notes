% Define parameters
SNR_dB = 0:2:20; % Range of SNR values in dB
numBits = 1e5;   % Number of bits
txData = randi([0 1], numBits, 1); % Generate random bits

% Initialize BER vector
BER = zeros(size(SNR_dB));

% Loop through each SNR value
for i = 1:length(SNR_dB)
    % Calculate noise variance based on SNR
    SNR_linear = 10^(SNR_dB(i)/10); % Convert dB to linear
    noiseVar = 1 / SNR_linear; % Noise variance
    
    % Generate Rayleigh fading channel coefficients
    h = 1/sqrt(2) * (randn(numBits, 1) + 1i * randn(numBits, 1)); % Rayleigh fading channel
    
    % Add AWGN to the transmitted signal
    noise = sqrt(noiseVar) * (randn(size(txData)) + 1i * randn(size(txData))); % Generate AWGN
    rxData = h .* txData + noise; % Received signal
    
    % Perform coherent demodulation
    demodulatedData = rxData ./ h;
    receivedBits = real(demodulatedData) > 0.5; % Threshold detection
    
    % Calculate BER
    BER(i) = sum(receivedBits ~= txData) / numBits;
end

% Plot the BER
figure;
semilogy(SNR_dB, BER, 'o-', 'LineWidth', 2);
grid on;
xlabel('SNR (dB)');
ylabel('Bit Error Rate (BER)');
title('BER under Rayleigh Fading Channel');
