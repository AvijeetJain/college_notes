def iterative_deepening_search(graph, start_node, goal_node):
    for depth_limit in range(len(graph)):
        visited = set()
        path = []
        if recursive_dls(graph, start_node, goal_node, visited, path, depth_limit):
            return path
    return None

def recursive_dls(graph, node, goal_node, visited, path, depth_limit):
    if node == goal_node:
        path.append(node)
        return True
    elif depth_limit == 0:
        return False
    else:
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                if recursive_dls(graph, neighbor, goal_node, visited, path, depth_limit-1):
                    path.insert(0, node)
                    return True
        return False
Graph = {
    "A" : ["B","C"],
    "B" : ["D","E"],
    "C" : ["F","G"],
    "D" : ["H","I"],
    "E" : ["J","K"],
    "F" : ["L","M"],
    "G" : ["N","O"],
    "H" : ["P","Q"],
    "I" : ["R","S"],
    "J" : ["T","U"],
    "K" : ["V","W"],
    "L" : ["X","Y"],
    "M" : ["Z","AA"],
    "N" : ["AB","AC"],
    "O" : ["AD","AE"],
    "P" : [],
    "Q" : [],
    "R" : [],
    "S" : [],
    "T" : [],
    "U" : [],
    "V" : [],
    "W" : [],
    "X" : [],
    "Y" : [],
    "Z" : [],
    "AA" : [],
    "AB" : [],
    "AC" : [],
    "AD" : [],
    "AE" : [],

}
path = iterative_deepening_search( Graph,'A', 'Z')
print("Iterative deepening search traversal :\n",path)