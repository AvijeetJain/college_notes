rng(0);

N = 10^5;
h1 = (randn(1, N) + 1i*randn(1,N)) / sqrt(2);

% Generating two additional channels
h2 = (randn(1, N) + 1i*randn(1,N)) / sqrt(2);
h3 = (randn(1, N) + 1i*randn(1,N)) / sqrt(2);

SNR_dB = -8:2:30;

SNR = 10.^(SNR_dB/10);
no = 1;
pt = SNR*no;

Pt = 10 * log10(pt); % power transmitted in dB
p = length(pt);
p1 = zeros(1, p);  % Array to store outage probabilities for one channel
p2 = zeros(1, p);  % Array to store outage probabilities for two channels
p3 = zeros(1, p);  % Array to store outage probabilities for three channels

rate = 1;  % desired bit rate

% For one channel
for u=1:p
    gamma = pt(u) * abs(h1).^2 / no;  % instantaneous SNR for each channel
    R = log2(1 + gamma);
    for k=1:N
        if R(k) < rate
            p1(u) = p1(u) + 1;
        end
    end
end

% For two channels (h1, h2)
for u=1:p
    % Calculate instantaneous SNR for each channel
    gamma1 = pt(u) * abs(h1).^2 / no;
    gamma2 = pt(u) * abs(h2).^2 / no;
    
    % Calculate weights for MRC
    w1 = gamma1 ./ (gamma1 + gamma2);
    w2 = gamma2 ./ (gamma1 + gamma2);
    
    % Combine SNRs using MRC
    combined_gamma = w1 .* gamma1 + w2 .* gamma2;
    
    % Calculate capacity for combined SNR
    R = log2(1 + combined_gamma);
    
    % Calculate outage probability
    for k=1:N
        if R(k) < rate
            p2(u) = p2(u) + 1;
        end
    end
end

% For three channels (h1, h2, h3)
for u=1:p
    % Calculate instantaneous SNR for each channel
    gamma1 = pt(u) * abs(h1).^2 / no;
    gamma2 = pt(u) * abs(h2).^2 / no;
    gamma3 = pt(u) * abs(h3).^2 / no;
    
    % Calculate weights for MRC
    w1 = gamma1 ./ (gamma1 + gamma2 + gamma3);
    w2 = gamma2 ./ (gamma1 + gamma2 + gamma3);
    w3 = gamma3 ./ (gamma1 + gamma2 + gamma3);
    
    % Combine SNRs using MRC
    combined_gamma = w1 .* gamma1 + w2 .* gamma2 + w3 .* gamma3;
    
    % Calculate capacity for combined SNR
    R = log2(1 + combined_gamma);
    
    % Calculate outage probability
    for k=1:N
        if R(k) < rate
            p3(u) = p3(u) + 1;
        end
    end
end

% Theoretical outage probability
theoretical_pout = 1 - exp(-no*(2^rate - 1)./pt);
pout1 = p1/N;
pout2 = p2/N;
pout3 = p3/N;

figure;

semilogy(Pt, pout1, '--','LineWidth',2);  % simulated outage for one channel
hold on;
semilogy(Pt, pout2, '--','LineWidth',2);  % simulated outage for two channels
semilogy(Pt, pout3, '--.','LineWidth',2);  % simulated outage for three channels
xlabel('Transmit Power(dB)');
ylabel('Outage Probability');
grid on;
legend('Simulated (One Channel)', 'Simulated (Two Channels)', 'Simulated (Three Channels)');