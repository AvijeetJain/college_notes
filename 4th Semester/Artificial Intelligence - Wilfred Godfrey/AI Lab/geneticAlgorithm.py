# Import necessary libraries
import random

# Define the graph as a dictionary
graph = {
    'A': {'B': 2, 'C': 3},
    'B': {'D': 4, 'E': 3},
    'C': {'F': 2},
    'D': {'G': 1},
    'E': {'G': 2},
    'F': {'G': 3},
    'G': {}
}

# Define the start and end nodes
start_node = 'A'
end_node = 'G'

# Define the genetic algorithm parameters
population_size = 100
num_generations = 100
mutation_rate = 0.1

# Define the graph search problem fitness function
def fitness_function(solution):
    total_cost = 0
    current_node = start_node
    for node in solution:
        if node in graph[current_node]:
            total_cost += graph[current_node][node]
            current_node = node
        else:
            return float('inf')
    return total_cost

# Define the genetic algorithm initialization function
def initialize_population(population_size):
    return [[start_node] + random.sample(list(graph.keys() - {start_node}), len(graph)-1) for _ in range(population_size)]

# Define the genetic algorithm mutation function
def mutate(solution, mutation_rate):
    for i in range(len(solution)):
        if random.random() < mutation_rate:
            solution[i] = random.choice(list(graph.keys() - {start_node, solution[i]}))
    return solution

# Define the genetic algorithm crossover function
def crossover(parent1, parent2):
    crossover_point = random.randint(1, len(parent1) - 1)
    child1 = parent1[:crossover_point] + parent2[crossover_point:]
    child2 = parent2[:crossover_point] + parent1[crossover_point:]
    return child1, child2

# Define the genetic algorithm selection function
def select(population, fitness_values):
    return random.choices(population, weights=[1/fit for fit in fitness_values], k=2)

# Implement the genetic algorithm
def genetic_search(graph, start_node, end_node, population_size, num_generations, mutation_rate):
    population = initialize_population(population_size)
    for generation in range(num_generations):
        fitness_values = [fitness_function(solution) for solution in population]
        best_solution = population[fitness_values.index(min(fitness_values))]
        if end_node in best_solution:
            return best_solution
        next_population = []
        while len(next_population) < population_size:
            parent1, parent2 = select(population, fitness_values)
            child1, child2 = crossover(parent1, parent2)
            child1 = mutate(child1, mutation_rate)
            child2 = mutate(child2, mutation_rate)
            next_population.extend([child1, child2])
        population = next_population
    return None

# Call the genetic search function and print the result
result = genetic_search(graph, start_node, end_node, population_size, num_generations, mutation_rate)
if result is None:
    print("No path found.")
else:
    print("path found : ", result)
