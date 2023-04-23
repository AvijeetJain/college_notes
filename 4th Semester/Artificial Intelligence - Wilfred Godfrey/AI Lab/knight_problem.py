class cell:
	def __init__(self, x=0, y=0, dist=0):
		self.x = x
		self.y = y
		self.dist = dist

def isInside(x, y, N):
	if (x >= 1 and x <= N and y >= 1 and y <= N):
		return True
	return False

def minStepToReachTarget(knightpos,targetpos, N):
	dx = [2, 2, -2, -2, 1, 1, -1, -1]
	dy = [1, -1, 1, -1, 2, -2, 2, -2]

	stack = []
	top = 0
	stack.append(cell(knightpos[0], knightpos[1], 0))
	visited = [[False for i in range(N + 1)]
			for j in range(N + 1)]

	visited[knightpos[0]][knightpos[1]] = True

	while(len(stack) > 0):
		t = stack[0]
		stack.pop(top)

		if(t.x == targetpos[0] and
		t.y == targetpos[1]):
			return t.dist

		for i in range(8):
			x = t.x + dx[i]
			y = t.y + dy[i]

			if(isInside(x, y, N) and not visited[x][y]):
				visited[x][y] = True
				stack.append(cell(x, y, t.dist + 1))
				print(x,y)

N = 8
A=int(input("Enter the origin x: "))
B=int(input("Enter the origin y: "))

knightpos = [A, B]

C=int(input("Enter the destination x: "))
D=int(input("Enter the destination y: "))

targetpos = [C, D]


print("The minimum number of steps to reach the target by a chess knight using DFS:-", minStepToReachTarget(knightpos,targetpos, N))