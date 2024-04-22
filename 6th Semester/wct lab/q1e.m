% Parameters
t = 0:0.0001:0.1;          % Time vector
fc = 1000;                 % Carrier frequency (Hz)
fm = 50;                   % Modulation frequency (Hz)
Ac = 1;                    % Carrier amplitude

% Modulation indices
m_values = [0, 0.5, 1];    % Modulation indices (0, 0.5, 1)

% Plotting
figure;

for i = 1:length(m_values)
    % Modulation amplitude for each modulation index
    Am = m_values(i) * Ac;  
    
    % Modulation signal
    m_t = Am * sin(2 * pi * fm * t);
    
    % Carrier signal
    c_t = Ac * sin(2 * pi * fc * t);
    
    % Modulated signal (AM)
    s_t = (1 + m_t) .* c_t;
    
    % Plotting AM wave
    subplot(length(m_values), 1, i);
    plot(t, s_t, 'LineWidth', 1.5);
    title(['AM Wave (m = ', num2str(m_values(i)), ')']);
    xlabel('Time (s)');
    ylabel('Amplitude');
    grid on;
end
