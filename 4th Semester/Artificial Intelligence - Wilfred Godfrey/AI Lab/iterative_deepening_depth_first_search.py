from collections import defaultdict

# Define a graph using a dictionary of edges and weights
graph = defaultdict(dict)
graph = {
    'A': {'B': 3, 'D': 7},
    'B': {'C': 4},
    'C': {'E': 10},
    'D': {'E': 5},
    'E': {'F': 6},
    'F': {}
}


def iddfs(start, end, max_depth):
    for depth in range(max_depth):
        visited = set()
        path = [start]
        cost = 0
        if dfs(start, end, depth, visited, path, cost):
            return path
    return None


def dfs(start, end, depth, visited, path, cost):
    if start == end:
        print("Minimum cost: ", cost)
        return True
    if depth <= 0:
        return False
    visited.add(start)
    for neighbor, weight in graph[start].items():
        if neighbor not in visited:
            path.append(neighbor)
            cost += weight
            if dfs(neighbor, end, depth-1, visited, path, cost):
                return True
            path.pop()
            cost -= weight
    return False


# Example usage
path = iddfs('A', 'F', 999999)
if path is None:
    print("No path found.")
else:
    print("Minimum cost path:", ' -> '.join(path))
