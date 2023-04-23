from collections import deque

def minimum_steps(source, target, visited, steps):
  
    if source == target:
        return steps
    visited.add(source)

    moves = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
    stack = deque()

    for move in moves:
        new_x, new_y = source[0] + move[0], source[1] + move[1]
        if (0 <= new_x < 8) and (0 <= new_y < 8) and ((new_x, new_y) not in visited):
            stack.appendleft((new_x, new_y))

    for pos in stack:
        result = minimum_steps(pos, target, visited, steps + 1)
        if result is not None:
            print("Current position:", pos)
            print("Length of stack:", len(stack))
            print("Elements in stack:", list(stack))
            return result

    return None

source = (0, 0)
target = (7, 7)
visited = set()
steps = 0
result = minimum_steps(source, target, visited, steps)
print("Minimum number of steps:", result)