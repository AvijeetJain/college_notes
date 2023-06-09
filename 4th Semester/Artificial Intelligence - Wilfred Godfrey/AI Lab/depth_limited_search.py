# graph = {
#     '5': ['3', '7'],
#     '3': ['2', '4'],
#     '7': ['8'],
#     '2': [],
#     '4': ['8'],
#     '8': []
# }

from collections import defaultdict


class Graph:

    def __init__(self, vertices):

        # No. of vertices
        self.V = vertices

        # default dictionary to store graph
        self.graph = defaultdict(list)

    # function to add an edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)

# A function to perform a Depth-Limited search
# from given source 'src'
    def DLS(self, src, target, maxDepth):
        if src == target:
            return True

    # If reached the maximum depth, stop recursing.
        if maxDepth <= 0:
            return False

    # Recur for all the vertices adjacent to this vertex
        for i in self.graph[src]:
            if(self.DLS(i, target, maxDepth-1)):
                return True
        return False


g = Graph(7)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 3)
g.addEdge(1, 4)
g.addEdge(2, 5)
g.addEdge(2, 6)


target = 6
maxDepth = 3
src = 0

if g.DLS(src, target, maxDepth) == True:
    print("Target is reachable from source " +
          "within max depth")
else:
    print("Target is NOT reachable from source " +
          "within max depth")
