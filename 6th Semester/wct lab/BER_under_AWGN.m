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
    
    % Add AWGN to the transmitted signal
    noise = sqrt(noiseVar) * randn(size(txData)); % Generate AWGN
    rxData = txData + noise; % Received signal
    
    % Perform hard decision decoding
    rxData(rxData >= 0.5) = 1;
    rxData(rxData < 0.5) = 0;
    
    % Calculate BER
    BER(i) = sum(rxData ~= txData) / numBits;
end

% Plot the BER
figure;
semilogy(SNR_dB, BER,'o-', 'LineWidth', 2);
%grid on;
xlabel('SNR (dB)');
ylabel('Bit Error Rate (BER)');
title('BER under AWGN channel');
