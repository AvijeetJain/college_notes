
% Parameters
B = 0.002; % Transmission rate
r = 0.4;   % Recovery rate

% Initial conditions
initialCondition = [500, 1]; % [Susceptible, Infected]

% Time span
tspan = [0, 50];

% Differential equations
dydt = @(t, y) [-B * y(1) * y(2); B * y(1) * y(2) - r * y(2)];

% Solve the differential equations
[t, y] = ode45(dydt, tspan, initialCondition);

% Plot the results
plot(t, y(:, 1), 'y-', 'LineWidth', 2); hold on;
plot(t, y(:, 2), 'g-', 'LineWidth', 1);
xlabel('Time');
ylabel('Population');
legend('Susceptible', 'Infected');
title('Disease Spread Simulation');