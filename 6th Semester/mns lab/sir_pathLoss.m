

% Define the range of SIR values
sir_range = 1:30;

% Define the range of path loss exponents
n_values = [2, 3, 4];

% Define the range of cluster sizes
cluster_sizes = 1:10;

% Initialize arrays to store the average and worst case SIR values
average_sir = zeros(length(n_values), length(cluster_sizes));
worst_case_sir = zeros(length(n_values), length(cluster_sizes));

% Loop over the path loss exponents
for i = 1:length(n_values)
    n = n_values(i);
    
    % Loop over the cluster sizes
    for j = 1:length(cluster_sizes)
        cluster_size = cluster_sizes(j);
        
        % Calculate the average and worst case SIR values for the given parameters
        average_sir(i, j) = calculate_average_sir(n, cluster_size, sir_range);
        worst_case_sir(i, j) = calculate_worst_case_sir(n, cluster_size, sir_range);
    end
end

% Plot the average SIR versus cluster size for different path loss exponents
figure;
hold on;
for i = 1:length(n_values)
    plot(cluster_sizes, average_sir(i, :), 'o-', 'DisplayName', sprintf('n = %d', n_values(i)));
end
hold off;
xlabel('Cluster Size');
ylabel('Average SIR (dB)');
legend('Location', 'best');
title('Average SIR versus Cluster Size for Different Path Loss Exponents');

% Plot the worst case SIR versus cluster size for different path loss exponents
figure;
hold on;
for i = 1:length(n_values)
    plot(cluster_sizes, worst_case_sir(i, :), 'o-', 'DisplayName', sprintf('n = %d', n_values(i)));
end
hold off;
xlabel('Cluster Size');
ylabel('Worst Case SIR (dB)');
legend('Location', 'best');
title('Worst Case SIR versus Cluster Size for Different Path Loss Exponents');

% Function to calculate the average SIR for given parameters
function average_sir = calculate_average_sir(n, cluster_size, sir_range)
    % Calculate the average SIR using the given formula
    average_sir = sum((1 ./ (1 + sir_range)).^cluster_size) / length(sir_range);
end

% Function to calculate the worst case SIR for given parameters
function worst_case_sir = calculate_worst_case_sir(n, cluster_size, sir_range)
    % Calculate the worst case SIR using the given formula
    worst_case_sir = min((1 ./ (1 + sir_range)).^cluster_size);
end