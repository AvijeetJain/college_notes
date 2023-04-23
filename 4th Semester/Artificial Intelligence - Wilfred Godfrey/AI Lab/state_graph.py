def dls(graph, start, goal, limit):
    if start == goal:
        return [start]
    if limit == 0:
        return None
    
    for neighbor in graph[start]:
        path = dls(graph, neighbor, goal, limit-1)
        if path is not None:
            return [start] + path
    
    return None
graph = {
    'Goshen':['Chesterfield','Williamsberg','Whately'],
    'Chesterfield':['Westhampton','Goshen','Williamsberg'],
    'Westhampton':['Easthampton','Chesterfield','Williamsberg','Northampton'],
    'Easthampton':['South Hadley','Westhampton','Northampton'],
    'Williamsberg':['Goshen','Chesterfield','Westhampton','Florence','Whately'],
    'Whately':['Hatfield','Amherst'],
    'Northampton':['Westhampton','Easthampton','South Hadley'],
    'Hatfield':['Florence','Amherst','Whately'],
    'Amherst':['South Hadley','Hatfield'],
    'Florence':['Northampton','Hatfield']
}
start = 'Goshen'
goal = 'South Hadley'
limit = 5

path = dls(graph, start, goal, limit)
if path is not None:
    print('Path found:', ' -> '.join(path))
else:
    print('No path found within depth limit.')
