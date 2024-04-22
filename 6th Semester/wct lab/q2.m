numBits = 10000;        
SNRdB = -10:1:10;       
BER_normal = zeros(size(SNRdB));  
BER_egc = zeros(size(SNRdB)); 

% Generate random binary data
data = randi([0,1],1,numBits);

for i = 1:length(SNRdB)
  
    modulatedSignal = 2*data - 1;
    
  
    fading1 = sqrt(1/2) * (randn(1, numBits) + 1i*randn(1, numBits)); % Rayleigh fading coefficients for channel 1
    fading2 = sqrt(1/2) * (randn(1, numBits) + 1i*randn(1, numBits)); % Rayleigh fading coefficients for channel 2
    
    
    receivedSignal_normal = modulatedSignal .* fading1;
    

    noisePower = 10^(-SNRdB(i)/10); % Calculate noise power
    noise = sqrt(noisePower) * (randn(1, numBits) + 1i*randn(1, numBits)); % Generate noise
    receivedSignal_normal = receivedSignal_normal + noise; % Add noise to the signal
    
    % BPSK demodulation without combining
    demodulatedData_normal = real(receivedSignal_normal) > 0; % Assume coherent detection
    
    % Calculate BER without combining
    BER_normal(i) = sum(data ~= demodulatedData_normal) / numBits;
    
    % Received signals with EGC combining
    receivedSignal_egc = (fading1 .* modulatedSignal + fading2 .* modulatedSignal) / sqrt(2); % Equal gain combining
    
    % Add AWGN
    receivedSignal_egc = receivedSignal_egc + noise; % Add noise to the signal
    
    % BPSK demodulation with EGC combining
    demodulatedData_egc = real(receivedSignal_egc) > 0; % Assume coherent detection
    
    % Calculate BER with EGC combining
    BER_egc(i) = sum(data ~= demodulatedData_egc) / numBits;
end

% Plot
figure;
semilogy(SNRdB, BER_normal, 'go-', 'DisplayName', 'Without Combining');
hold on;
semilogy(SNRdB, BER_egc, 'bo-', 'DisplayName', 'With EGC Combining');
hold off;
grid on;
title('BER vs SNR for BPSK Modulation under Rayleigh Fading Channel');
xlabel('SNR (dB)');
ylabel('Bit Error Rate (BER)');
legend;