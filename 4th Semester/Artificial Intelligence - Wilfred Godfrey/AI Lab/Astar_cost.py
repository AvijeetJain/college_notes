from queue import PriorityQueue

def a_star(graph, start, goal, heuristic):

    frontier = PriorityQueue()
    frontier.put(start, 0)
    came_from = {start: None}
    cost_so_far = {start: 0}

    while not frontier.empty():
        current = frontier.get()

        if current == goal:
            break

        for neighbor in graph[current]:
            new_cost = cost_so_far[current] + graph[current][neighbor]
            if neighbor not in cost_so_far or new_cost < cost_so_far[neighbor]:
                cost_so_far[neighbor] = new_cost
                priority = new_cost + heuristic(neighbor, goal)
                frontier.put(neighbor, priority)
                came_from[neighbor] = current

    path = []
    current = goal
    while current != start:
        path.append(current)
        current = came_from[current]
    path.append(start)
    path.reverse()

    cost = cost_so_far[goal]
    return path, cost


graph = {
    'S': {'B': 2, 'A': 4},
    'B': {'A': 1},
    'A': {'G': 4},
    'G': {}
}

# Test the A* algorithm implementation
path, cost = a_star(graph, 'S', 'G', lambda a, b: 0)
print("Path:", path)
print("Total Cost:", cost)