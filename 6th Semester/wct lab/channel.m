rng(0);

N = 10^5;

h = (randn(1, N) + 1i * randn(1, N)) / sqrt(2);

SNR_dB = -8:2:30;

SNR = 10.^(SNR_dB / 10);

no = 1;

pt = SNR * no;

Pt = 10 * log10(pt);

p = length(pt);

p1 = zeros(1,p);

rate = 1;

for u = 1 : p
    gamma = pt(u) * abs(h).^2 / no;

    R = log2(1  + gamma);

    for k = 1:N
        if R(k) < rate
            p1(u) = p1(u) + 1;
        end
    end
end

theoretical_pout = 1 - exp(-no*(2^rate - 1)./pt);

pout = p1 / N;

figure;
semilogy(Pt, theoretical_pout, '.', 'LineWidth',2);
hold on;
semilogy(Pt, pout, 'o', 'LineWidth',2);
xlabel('Transmit Power dB');
ylabel('Outage Probability');
grid on;
legend('Theoretical', 'Simulated');