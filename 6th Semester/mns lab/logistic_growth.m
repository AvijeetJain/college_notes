% Logistic growth model parameters
r = 0.08;     % Growth rate
K = 600;    % Carrying capacity

% Define the logistic growth function
logistic_grow = @(t, x) r * x * (1 - x / K);

% Set the time span
tspan = [0, 200];

% Set the initial population
initialPopulation = 20;

% Use ode45 to solve the logistic growth equation
[t, x] = ode45(logistic_grow, tspan, initialPopulation);

% Plot the solution
plot(t, x)
xlabel('Time (t)')
ylabel('Population (x)')
title('Logistic Growth Model')
grid on;