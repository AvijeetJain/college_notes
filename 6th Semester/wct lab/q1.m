t = 0:0.0001:0.1; 
fm = 50; 
fc = 1000; 


m = sin(2*pi*fm*t);
c = sin(2*pi*fc*t);

m_index = [0, 0.5, 1];

figure;
for i = 1:length(m_index)
    subplot(length(m_index), 1, i);
    modulated_signal = (1 + m_index(i)*m).*c;
    plot(t, m, 'b', t, c, 'r', t, modulated_signal, 'g');
    title(['Modulation Index = ', num2str(m_index(i))]);
    xlabel('Time (s)');
    ylabel('Amplitude');
    legend('Message Signal', 'Carrier Signal', 'Modulated Signal');
    grid on;
end