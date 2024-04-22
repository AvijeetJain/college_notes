dydt = @(t, x) x*x + x+1;

tspan = [0,10000];

y0 = 1;

h = 0.1;

t_values = tspan(1):h:tspan(2);
y_values = zeros(size(t_values));

y_values(1) = y0;

for i = 1:length(t_values) -1
    y_values(i+1) = y_values(i) + h *dydt(t_values(i), y_values(i));
end

figure;
plot(t_values, y_values, "-o", 'LineWidth', 0.2);
xlabel('t');
ylabel('y(t)');
title('Title');
grid on;