% Exponential decay parameters
initialPopulation = 1000;  % Initial population
decayRate = 0.05;         % Decay rate

% Time vector
time = 0:1:500;  % Assuming the decay occurs over 50 time steps

% Exponential decay model
population = initialPopulation * exp(-decayRate * time);

% Plotting the population decay
figure;
plot(time, population, 'b-', 'LineWidth', 2);
title('Population Decay Over Time');
xlabel('Time');
ylabel('Population');
grid on;
