function ode_solver()
    % Parameters
    b = 0.002;
    y_param = 0.4;
    a = 0.5;

    % Initial conditions
    S0 = 500;
    I0 = 1;
    R0 = 0;
    initial_conditions = [S0; I0; R0];

    % Time span
    tspan = [0, 50];

    % Solve the ODE system
    [t, solution] = ode45(@(t, y) odefun(t, y, b, y_param, a), tspan, initial_conditions);

    % Extracting S, I, and R from the solution
    S = solution(:, 1);
    I = solution(:, 2);
    R = solution(:, 3);

    % Plotting
    figure;
    plot(t, S, 'y-', 'LineWidth', 2, 'DisplayName', 'Susceptible (S)');
    hold on;
    plot(t, I, 'LineWidth', 2, 'DisplayName', 'Infected (I)');
    plot(t, R, 'g-', 'LineWidth', 2, 'DisplayName', 'Recovered (R)');
    hold off;

    title('S, I, R vs Time');
    xlabel('Time (t)');
    ylabel('Population');
    legend('Location', 'Best');
    grid on;
end

function dydt = odefun(t, y, b, y_param, a)
    % ODE system
    S = y(1);
    I = y(2);
    R = y(3);
    
    dSdt = -b * S * I;
    dIdt = b * S * I - y_param * I - a * I;
    dRdt = a * I;
    
    dydt = [dSdt; dIdt; dRdt];
end