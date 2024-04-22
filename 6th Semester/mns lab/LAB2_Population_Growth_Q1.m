% Given parameters
x0 = 100; % Initial population size
dt = 1; % Time step size
numSteps = 20; % Number of steps

% Initialize arrays
populationSizes = zeros(1, numSteps+1);
populationSizes(1) = x0;

% Population model function
populationModel = @(x) 0.2 * x - 0.001 * x * x;

% Calculate population size after each time step
for i = 1:numSteps
    x = populationSizes(i);
    x_next = x + dt * populationModel(x);
    populationSizes(i+1) = x_next;
end

% Print the predicted population size after 20 months
fprintf('Population size after 20 months: %.2f\n', populationSizes(end));

% Plot the overall graph
months = 0:numSteps;
figure;
plot(months, populationSizes);
xlabel('Months');
ylabel('Population Size');
title('Population Growth Over Time');
