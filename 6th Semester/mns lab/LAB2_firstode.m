% FILEPATH: /c:/Users/Spedrik Webster/Documents/Programming/Projects/p2p-file-transfer/solver.m

% Write a matlab code to plot the 
% solution of logistic growth model 
% with r as growth rate = 0.08 per day, 
% K as Carrying capacity = 600 per km^2, 

% Initial population 
% P(0) = 20,40,100,500,1000,1200,1500. 

% Parameters
r = 0.08; % Growth rate per day
K = 600; % Carrying capacity per km^2

% Initial populations
P0 = [20, 40, 100, 500, 1000, 1200, 1500];

% Time span
t = 0:0.1:150; % Time span from 0 to 100 days with a step size of 0.1

% Solve logistic growth model for each initial population
for i = 1:length(P0)
    P = K / (1 + ((K - P0(i)) / P0(i)) * exp(-r * t));
    plot(t, P);
    hold on;
end

% Add labels and legend
xlabel('Time (days)');
ylabel('Population');
legend('P(0) = 20', 'P(0) = 40', 'P(0) = 100', 'P(0) = 500', 'P(0) = 1000', 'P(0) = 1200', 'P(0) = 1500');
