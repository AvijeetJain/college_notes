#8 PUZZLE USING BEST FIRST SEARCH
#f(n) = h(n)

def h(board, goal):
    count = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] != goal[i][j]:
                count += 1
    return count

def ast(board, goal):
    q = [[board, 0]]
    visited = []

    while q:
        curr = q.pop(0)
        visited.append(tuple(map(tuple, curr[0])))

        print("Current state:")
        for row in curr[0]:
            print(row)
        print("Cost so far:", curr[1])
        print()

        if curr[0] == goal:
            return curr[1]

        x, y = 0, 0
        for i in range(3):
            for j in range(3):
                if curr[0][i][j] == 0:
                    x, y = i, j

        neighbors = []
        if x > 0:
            t = [list(row) for row in curr[0]]
            t[x][y], t[x-1][y] = t[x-1][y], t[x][y]
            if tuple(map(tuple, t)) not in visited:
                q.append([t, curr[1]+1])
                q = sorted(q, key=lambda x: h(x[0], goal) + x[1])

        if x < 2:
            t = [list(row) for row in curr[0]]
            t[x][y], t[x+1][y] = t[x+1][y], t[x][y]
            if tuple(map(tuple, t)) not in visited:
                q.append([t, curr[1]+1])
                q = sorted(q, key=lambda x: h(x[0], goal) + x[1])

        if y > 0:
            t = [list(row) for row in curr[0]]
            t[x][y], t[x][y-1] = t[x][y-1], t[x][y]
            if tuple(map(tuple, t)) not in visited:
                q.append([t, curr[1]+1])
                q = sorted(q, key=lambda x: h(x[0], goal) + x[1])

        if y < 2:
            t = [list(row) for row in curr[0]]
            t[x][y], t[x][y+1] = t[x][y+1], t[x][y]
            if tuple(map(tuple, t)) not in visited:
                q.append([t, curr[1]+1])
                q = sorted(q, key=lambda x: h(x[0], goal) + x[1])

board = [[1, 2, 3], [5, 6, 0], [7, 8, 4]]
goal = [[1, 2, 3], [5, 8, 6], [0, 7, 4]]

ast(board, goal)