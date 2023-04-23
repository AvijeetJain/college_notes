from queue import PriorityQueue

class EIGHT_PUZZLE:
    def __init__(self, board, goal, moves=0):
        self.board = board
        self.goal = goal
        self.moves = moves
        self.blank = self.get_blank()

    def get_blank(self):
        for i in range(3):
            for j in range(3):
                if self.board[i][j] == 0:
                    return i, j

    def get_neighbors(self):
        neighbors = []
        row, col = self.blank

        if row > 0:
            board_copy = self.copy_board()
            board_copy[row][col], board_copy[row-1][col] = board_copy[row-1][col], board_copy[row][col]
            neighbors.append(EIGHT_PUZZLE(board_copy, self.goal, self.moves+1))

        if row < 2:
            board_copy = self.copy_board()
            board_copy[row][col], board_copy[row+1][col] = board_copy[row+1][col], board_copy[row][col]
            neighbors.append(EIGHT_PUZZLE(board_copy, self.goal, self.moves+1))

        if col > 0:
            board_copy = self.copy_board()
            board_copy[row][col], board_copy[row][col-1] = board_copy[row][col-1], board_copy[row][col]
            neighbors.append(EIGHT_PUZZLE(board_copy, self.goal, self.moves+1))

        if col < 2:
            board_copy = self.copy_board()
            board_copy[row][col], board_copy[row][col+1] = board_copy[row][col+1], board_copy[row][col]
            neighbors.append(EIGHT_PUZZLE(board_copy, self.goal, self.moves+1))

        return neighbors
    def copy_board(self):
        return [row[:] for row in self.board]

    def heuristic(self):
        distance = 0
        for i in range(3):
            for j in range(3):
                if self.board[i][j] != self.goal[i][j]:
                    distance += abs(i - (self.goal[i][j] // 3)) + abs(j - (self.goal[i][j] % 3))
        return distance

    def __lt__(self, other):
        return self.heuristic() < other.heuristic()

    def __eq__(self, other):
        return self.board == other.board

    def __hash__(self):
        return hash(str(self.board))

    def __str__(self):
        s = ""
        for i in range(3):
            for j in range(3):
                s += str(self.board[i][j]) + " "
            s += "\n"
        return s

def best_first_search(initial, goal):
    queue = PriorityQueue()
    visited = set()
    queue.put(initial)

    while not queue.empty():
        current = queue.get()

        if current.board == goal:
            print(current)
            return current.moves

        print(current)

        for neighbor in current.get_neighbors():
            if neighbor not in visited:
                visited.add(neighbor)
                queue.put(neighbor)

    return None

initial_board = [[1, 2, 3], [5, 6, 0], [7, 8, 4]]
goal_board = [[1, 2, 3], [5, 8, 6], [7,0, 4]]

initial_puzzle = EIGHT_PUZZLE(initial_board, goal_board)

print(best_first_search(initial_puzzle, goal_board))
