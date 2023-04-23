import heapq

graph = {
    'A': {'B': 2, 'E': 3},
    'B': {'C': 1, 'G': 9},
    'C': {'B':1},
    'D': {'G': 1, 'E': 6},
    'E': {'A': 3, 'D':6},
    'G': {'B': 9, 'D': 1}
}

heuristic = {
    'A': 11,
    'B': 6,
    'C': 99,
    'D': 1,
    'E': 7,
    'G': 0
}

def weighted_a_star(start, goal, graph, heuristic, weight):
    open_list = [(0, start)]
    closed_list = {}

    g_values = {node: float('inf') for node in graph}
    f_values = {node: float('inf') for node in graph}

    g_values[start] = 0

    while open_list:
        current = heapq.heappop(open_list)[1]

        if current == goal:
            path = [current]
            while current != start:
                current = closed_list[current][1]
                path.append(current)
            path.reverse()
            return path

        closed_list[current] = (f_values[current], closed_list.get(current, (None, None))[1])

        for neighbor, cost in graph[current].items():
            tentative_g_value = g_values[current] + cost * weight

            if neighbor in closed_list:
                continue

            if not any(neighbor == item[1] for item in open_list):
                f_value = tentative_g_value + heuristic[neighbor] * weight
                heapq.heappush(open_list, (f_value, neighbor))
            elif tentative_g_value >= g_values[neighbor]:
                continue

            g_values[neighbor] = tentative_g_value
            f_values[neighbor] = tentative_g_value + heuristic[neighbor] * weight
            closed_list[neighbor] = (f_values[neighbor], current)

    return None

path = weighted_a_star('A', 'G', graph, heuristic, 11)

print("The path obtained using the weighted A* algorithm is")
print(path)