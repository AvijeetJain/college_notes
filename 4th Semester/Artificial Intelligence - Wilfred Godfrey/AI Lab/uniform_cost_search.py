#This code is submitted by Avijeet Jain

from collections import deque

def uniform_cost_search(graph, start):
    cost = {node: float('inf') for node in graph}
    cost[start] = 0
    parent = {node: None for node in graph}
    queue = deque([start])

    while queue:
        node = queue.popleft()
        for neighbor, cost_to_neighbor in graph[node].items():
            new_cost = cost[node] + cost_to_neighbor
            if new_cost < cost[neighbor]:
                cost[neighbor] = new_cost
                parent[neighbor] = node
                queue.append(neighbor)
    return cost, parent

graph = {
    'a': {'b': 5, 'c': 4},
    'b': {'d': 3},
    'c': {'b': 1,
          'f': 8
        },
    'd': {
        'a': 4,
        'c': 6,
        'e': 3,
        'g': 7
        },
    'e': {'b': 2},
    'f': {'g': 7},
    'g': {'e': 2}
    }

for start in graph:
    cost, parent = uniform_cost_search(graph, start)
    print("Starting from node:", start)
    print("Minimum cost to all other nodes:", cost)
    print("Path to all other nodes:", parent)
    print("\n")

