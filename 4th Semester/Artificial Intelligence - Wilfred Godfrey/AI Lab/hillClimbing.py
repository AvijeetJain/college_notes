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

# Define the initial state and goal state
initial_state = 'A'
goal_state = 'G'

# Define the hill climbing search function
def hill_climbing_search(graph, initial_state, goal_state):
    current_state = initial_state
    path = [current_state]
    while current_state != goal_state:
        neighbors = graph[current_state]
        best_state = None
        best_cost = float('inf')
        for neighbor in neighbors:
            cost = neighbors[neighbor]
            if cost < best_cost:
                best_state = neighbor
                best_cost = cost
        if best_cost >= float('inf'):
            return None
        current_state = best_state
        path.append(current_state)
    return path

# Call the hill climbing search function and print the result
result = hill_climbing_search(graph, initial_state, goal_state)
if result is None:
    print("No path found.")
else:
    print("Path found:", result)
