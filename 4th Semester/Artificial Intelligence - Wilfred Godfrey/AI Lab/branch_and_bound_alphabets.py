# If f-value is given directly

from collections import defaultdict
graph = defaultdict(list)


def addEdge(graph, u, v, w):
    graph[u].append((v, w))


def sort(sub_li):
    return(sorted(sub_li, key=lambda x: (x[1], len(x[0]))))


visited = {'S': False, 'A': False, 'B': False, 'C': False,
           'D': False, 'E': False, 'F': False, 'G': False}

addEdge(graph, 'S', 'A', 120)
addEdge(graph, 'S', 'B', 130)
addEdge(graph, 'S', 'C', 120)
addEdge(graph, 'A', 'D', 140)
addEdge(graph, 'A', 'G', 125)
addEdge(graph, 'C', 'E', 140)
addEdge(graph, 'C', 'F', 125)

addEdge(graph, 'A', 'S', 100)
addEdge(graph, 'B', 'S', 100)
addEdge(graph, 'C', 'S', 100)
addEdge(graph, 'D', 'A', 120)
addEdge(graph, 'G', 'A', 120)
addEdge(graph, 'E', 'C', 120)
addEdge(graph, 'F', 'C', 120)

priority_queue = [['S', 100]]
while(len(priority_queue) != 0):
    top = priority_queue.pop(0)
    path = top[0]
    node = path[len(path)-1]
    if(node == 'E'):
        print(path)

    for neighbour in graph[node]:
        adj = neighbour[0]
        fvalue = neighbour[1]
        if(visited[adj] == False):
            push = [path+adj, fvalue]
            priority_queue.append(push)
    visited[node] = True
    priority_queue = sort(priority_queue)
