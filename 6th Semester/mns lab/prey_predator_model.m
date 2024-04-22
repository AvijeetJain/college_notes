% Initial conditions
X0 = 80;
Y0 = 20;

% Parameters
r = 0.1;
k = 100;
a = 0.02;
b = 0.02;
d = 0.2;

% Defining the system of equations for the prey-predator
dydt = @(t, y) [r*y(1)*(1-y(1)/k) - a*y(1)*y(2); b*y(1)*y(2) - d*y(2)];

% Solve the system of equations using ode45 solver
[t, y] = ode45(dydt, [0, 1000], [X0, Y0]);

% Ploting the results
plot(t, y(:, 1), 'g', t, y(:, 2), 'r');
ylabel('Population');
xlabel('Time');
legend('Prey (X)', 'Predator (Y)');