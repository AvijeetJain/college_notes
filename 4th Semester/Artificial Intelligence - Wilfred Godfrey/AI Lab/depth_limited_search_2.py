def depth_limited_search(graph, start_node, goal_node, depth_limit):
    visited = set()
    stack = [(start_node, 0)]

    while stack:
        current_node, depth = stack.pop()

        print(f"Current node: {current_node}, depth: {depth}")

        if current_node == goal_node:
            return True

        if depth < depth_limit:
            visited.add(current_node)
            for neighbor in graph[current_node]:
                if neighbor not in visited:
                    stack.append((neighbor, depth+1))

    return False


graph = {
    '1': ['2', '3'],
    '2': ['4', '5'],
    '3': ['6', '7'],
    '4': ['8'],
    '5': ['9'],
    '9': [],
    '6': [],
    '7': ['10', '11'],
    '8': ['12'],
    '12': [],
    '10': [],
    '11': []
}

start_node = '1'
goal_node = '12'
depth_limit = 100

result = depth_limited_search(graph, start_node, goal_node, depth_limit)

if result:
    print(
        f"Goal node '{goal_node}' found from '{start_node}'")
else:
    print(
        f"Goal node '{goal_node}' not found from '{start_node}'")
