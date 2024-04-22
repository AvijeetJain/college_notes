% Parameters
r = 0.1;    % Birth rate of prey
a1 = 0.02;  % Death rate of prey due to predation
a2 = 0.01;  % Reproduction rate of predator per prey eaten
d = 0.05;   % Death rate of predator

% Initial conditions
x0 = 40;  % Initial population of prey
y0 = 9;   % Initial population of predator

% Simulation settings
tspan = [0 200];  % Time span for simulation

% Define the prey-predator model as a system of differential equations
odefun = @(t, y) [r*y(1) - a1*y(1)*y(2); a2*y(1)*y(2) - d*y(2)];

% Solve the differential equations
[t, populations] = ode45(odefun, tspan, [x0, y0]);

% Extract populations of prey and predator
prey = populations(:, 1);
predator = populations(:, 2);

% Plot the results
figure;
plot(t, prey, 'b', 'LineWidth', 2);
hold on;
plot(t, predator, 'r', 'LineWidth', 2);
xlabel('Time');
ylabel('Population');
title('Prey-Predator Model');
legend('Prey (x)', 'Predator (y)');
grid on;
