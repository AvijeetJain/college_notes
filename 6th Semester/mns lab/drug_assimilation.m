% Parameters
k1 = 0.1;  % Rate constant for drug absorption
k2 = 0.05; % Rate constant for drug elimination

% Initial conditions
x0 = 100;  % Initial amount of drug in the pill
y0 = 0;    % Initial amount of drug in the bloodstream

% Simulation settings
simulationTime = 500;  % Simulation time in hours
timeStep = 0.1;       % Time step for simulation

% Initialize arrays to store results
timePoints = 0:timeStep:simulationTime;
x = zeros(size(timePoints));
y = zeros(size(timePoints));

% Set initial conditions
x(1) = x0;
y(1) = y0;

% Simulate drug assimilation
for i = 2:length(timePoints)
    % Calculate rate of change of x and y
    dxdt = -k1 * x(i-1);
    dydt = k1 * x(i-1) - k2 * y(i-1);
    
    % Update x and y using Euler's method
    x(i) = x(i-1) + dxdt * timeStep;
    y(i) = y(i-1) + dydt * timeStep;
end

% Plot the results
plot(timePoints, x, 'b', 'LineWidth', 2);
hold on;
plot(timePoints, y, 'r', 'LineWidth', 2);
xlabel('Time (hours)');
ylabel('Amount of Drug');
title('Drug Assimilation Model');
legend('Drug in Pill (x)', 'Drug in Bloodstream (y)');
grid on;
