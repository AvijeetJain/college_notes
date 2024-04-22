% Simulation of the SIR model
beta = 0.5; % Infection rate
gamma = 0.2; % Recovery rate
s0 = 0.9; % Initial susceptible population
i0 = 0.1; % Initial infected population
r0 = 0; % Initial recovered population
tspan = [0 100]; % Time span for simulation

% Solve the differential equations
[t, y] = ode45(@(t, y) Lab4_disease_spread1(beta, gamma, y(1), y(2), y(3)), tspan, [s0 i0 r0]);

% Plot the results
plot(t, y(:, 1), 'r', t, y(:, 2), 'g', t, y(:, 3), 'b');
xlabel('Time');
ylabel('Population');
legend('Susceptible', 'Infected', 'Recovered');
title('SIR Model Simulation');

function [dsdt, didt, drdt] = Lab4_disease_spread1(beta, gamma, s, i, r)
    % Calculate the derivatives of S, I, and R
    dsdt = -beta * s * i;
    didt = beta * s * i - gamma * i;
    drdt = gamma * i;
end

function [S,I,R] = sirs_model(beta,gamma,delta,N,I0,T,dt)
    % if delta = 0 we have a SIR model (particular case)
    S = zeros(1,T/dt);
    S(1) = N;
    I = zeros(1,T/dt);
    I(1) = I0;
    R = zeros(1,T/dt);
    for tt = 1:(T/dt)-1
        % Equations of the model
        dS = (-beta*I(tt)*S(tt) + delta*R(tt)) * dt;
        dI = (beta*I(tt)*S(tt) - gamma*I(tt)) * dt;
        dR = (gamma*I(tt) - delta*R(tt)) * dt;
        S(tt+1) = S(tt) + dS;
        I(tt+1) = I(tt) + dI;
        R(tt+1) = R(tt) + dR;
    end
end
