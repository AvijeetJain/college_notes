f = 900e6; % Frequency of transmission (Hz)
R = -1; % Reflection coefficient
Pt = 1; % Transmitted power in mW
Glos = 1; % Product of tx, rx antenna patterns in LOS direction
Gref = 1; % Product of tx, rx antenna patterns in reflection direction
ht = 50; % Height of tx antenna (m)
hr = 2; % Height of rx antenna (m)
d = 1:0.1:10^5; % Separation distance between the tx-rx antennas (m)
L = 1; % No system losses

% Two-ray ground reflection model
d_los = sqrt((ht - hr)^2 + d.^2); % Distance along LOS path
d_ref = sqrt((ht + hr)^2 + d.^2); % Distance along reflected path
lambda = 3 * 10^8 / f; % Wavelength of the propagating wave
phi = 2 * pi * (d_ref - d_los) / lambda; % Phase difference between the paths
s = lambda / (4 * pi) * (sqrt(Glos) ./ d_los + R * sqrt(Gref) ./ d_ref .* exp(1i * phi));
Pr = Pt * abs(s).^2; % Received power
Pr_norm = Pr / Pr(1); % Normalized received power to start from 0 dBm

% Plotting
figure;
semilogx(d, 10 * log10(Pr_norm));
hold on;
ylim([-160 -55]);
title('Two-ray ground reflection model');
xlabel('log_{10}(d)');
ylabel('Normalized Received power (in dB)');

% Approximate models in three different regions
dc = 4 * ht * hr / lambda; % Critical distance
d1 = 1:0.1:ht; % Region 1 -- d <= ht
d2 = ht:0.1:dc; % Region 2 -- ht <= d <= dc
d3 = dc:0.1:10^5; % Region 3 -- d >= dc
K_fps = Glos * Gref * lambda^2 / ((4 * pi)^2 * L);
K_2ray = Glos * Gref * ht^2 * hr^2 / L;
Pr1 = Pt * K_fps ./ (d1.^2 + ht^2); % Received power in region 1
Pr2 = Pt * K_fps ./ d2.^2; % Received power in region 2
Pr3 = Pt * K_2ray ./ d3.^4; % Received power in region 3

semilogx(d1, 10 * log10(Pr1), 'k-.'); % Pr in region 1
semilogx(d2, 10 * log10(Pr2), 'r-.'); % Pr in region 2
semilogx(d3, 10 * log10(Pr3), 'g-.'); % Pr in region 3

h = line([ht ht], [-160 -55]);
set(h, 'Color', 'm');
h = line([dc dc], [-160 -55]);
set(h, 'Color', 'm');

legend('Two-ray ground reflection model', 'Region 1', 'Region 2', 'Region 3', 'Location', 'Best');