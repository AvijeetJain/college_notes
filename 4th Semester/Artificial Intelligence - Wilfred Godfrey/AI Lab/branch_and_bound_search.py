from queue import PriorityQueue


class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                      for row in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight
        self.graph[v][u] = weight

    def branch_and_bound(self, source, dest):
        pq = PriorityQueue()
        pq.put((0, source, [source]))
        min_cost = float('inf')
        while not pq.empty():
            (cost, node, path) = pq.get()
            if node == dest:
                if cost < min_cost:
                    min_cost = cost
                    min_path = path
            for next_node in range(self.V):
                if self.graph[node][next_node] > 0 and next_node not in path:
                    new_cost = cost + self.graph[node][next_node]
                    bound = new_cost + self.heuristic(next_node, dest)
                    if bound < min_cost:
                        new_path = path.copy()
                        new_path.append(next_node)
                        pq.put((new_cost, next_node, new_path))
        return min_path, min_cost

    def heuristic(self, current, dest):
        # This is a simple heuristic function that calculates the distance between two nodes
        return abs(current - dest)


g = Graph(7)
g.add_edge(0, 1, 5)
g.add_edge(0, 2, 4)
g.add_edge(1, 3, 4)
g.add_edge(1, 4, 4)
g.add_edge(1, 2, 3)
g.add_edge(2, 4, 8)
g.add_edge(2, 5, 15)
g.add_edge(4, 5, 2)
g.add_edge(4, 6, 2)
g.add_edge(3, 6, 7)

path, cost = g.branch_and_bound(0, 6)
print("Shortest path:", path)
print("Cost:", cost)
