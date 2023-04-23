graph = {'5':['3','7','8'],
         '3':['4','2'],
         '7':['1'],
         '8':['6','9'],
         '4':[],'2':[],'1':[],'6':[],'9':[]
        }

visited = set() # Set to keep track of visited nodes of graph.

def dfs(visited, graph, node):  #function for dfs 
    if node not in visited:
        print (node," -> ", end="")
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)

# Driver Code
print("Following is the Depth-First Search")
dfs(visited, graph, '5')
print("")


