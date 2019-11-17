import sys
from collections import deque

sys.setrecursionlimit(10**6)

N = int(input())
ans = 3001
t_ans = 0
cant = False
field = []
c_field = [[False for _ in range(N)] for _ in range(N)]
dx = (1, 0, -1, 0, 0, 2, 1, 1, 0, 0, -1, -1, -2)
dy = (0, 1, 0, -1, 0, 0, 1, -1, 2, -2, 1, -1 ,0)
for i in range(N):
	field.append(list(map(int, sys.stdin.readline().split())))

c_field = [[1001 for _ in range(N)] for _ in range(N)]
for i in range(1, N - 1):
	for j in range(1, N - 1):
		c_field[i][j] = 0
		for d in range(5):
			nx = j + dx[d]
			ny = i + dy[d]
			if nx < 0 or ny < 0 or nx >= N or ny >= N:
				continue
			c_field[i][j] += field[ny][nx]


def dfs(D):
	global t_ans
	global ans
	global c_field
	global cant
	q = deque()
	if D == 3:
		ans = min(t_ans, ans)
		return

	temp = min(min(c_field))
	for i in range(1, N - 1):
		for j in range(1, N - 1):
			if c_field[i][j] == temp:
				for d in range(13):
					nx = j + dx[d]
					ny = i + dy[d]
					if nx < 1 or ny < 1 or nx >= N - 1 or ny >= N - 1:
						continue
					q.append((d, c_field[ny][nx]))
					if c_field[ny][nx] > 1000 and d == 4:
						q = deque()
						cant = True
						break
				if cant:
					cant = False
					continue
				for d in range(len(q)):
					nx = j + dx[q[d][0]]
					ny = i + dy[q[d][0]]
					c_field[ny][nx] = 1001

				t_ans += temp
				dfs(D + 1)

				while q:
					d, ori = q.popleft()
					nx = j + dx[d]
					ny = i + dy[d]
					c_field[ny][nx] = ori
				t_ans -= temp

dfs(0)

print(ans)
