% Define initial population sizes
popA = 100; % Initial population of side A
popB = 120; % Initial population of side B

% Define death rates
alpha1 = 0.1; % Death rate for side A
alpha2 = 0.15; % Death rate for side B

% Define simulation parameters
numIterations = 100; % Number of iterations for the simulation

% Initialize arrays to store population sizes over time
popA_history = zeros(1, numIterations);
popB_history = zeros(1, numIterations);

% Simulate battle
for t = 1:numIterations
    % Update population sizes based on death rates
    popA = popA * (1 - alpha1);
    popB = popB * (1 - alpha2);
    
    % Store population sizes at each iteration
    popA_history(t) = popA;
    popB_history(t) = popB;
end

% Plot the results
time = 1:numIterations;
plot(time, popA_history, 'b', 'LineWidth', 2);
hold on;
plot(time, popB_history, 'r', 'LineWidth', 2);
xlabel('Time');
ylabel('Population');
title('Population Dynamics in Battle');
legend('Side A', 'Side B');
grid on;
