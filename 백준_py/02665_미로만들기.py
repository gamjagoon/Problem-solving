from collections import deque

n = int(input())
Maze = [['0' for _ in range(n+1)]]
for _ in range(n):
    tmp = (list(input()))
    tmp.insert(0, '0')
    Maze.append(tmp)
Maze.append(['0' for _ in range(n+1)])
Dist = [50 for _ in range(5152)]
dq = deque()
dq.appendleft((1, 1))
Dist[101] = 0

while dq:
    r, c = dq.popleft()
    distance = r * 100 + c
    if r + 1 <= n:
        cost = 0
        nr = r + 1
        if Maze[nr][c] == '0':
            cost = 1
        if Dist[(nr * 100) + c] > Dist[distance] + cost:
            Dist[(nr * 100) + c] = Dist[distance] + cost
            if cost == 1:
                dq.append((nr, c))
            else:
                dq.appendleft((nr, c))
    if r - 1 > 0:
        cost = 0
        nr = r - 1
        if Maze[nr][c] == '0':
            cost = 1
        if Dist[(nr * 100) + c] > Dist[distance] + cost:
            Dist[(nr * 100) + c] = Dist[distance] + cost
            if cost == 1:
                dq.append((nr, c))
            else:
                dq.appendleft((nr, c))
    if c + 1 <= n:
        cost = 0
        nc = c + 1
        if Maze[r][nc] == '0':
            cost = 1
        if Dist[(r * 100) + nc] > Dist[distance] + cost:
            Dist[(r * 100) + nc] = Dist[distance] + cost
            if cost == 1:
                dq.append((r, nc))
            else:
                dq.appendleft((r, nc))
    if c - 1 > 0:
        cost = 0
        nc = c - 1
        if Maze[r][nc] == '0':
            cost = 1
        if Dist[(r * 100) + nc] > Dist[distance] + cost:
            Dist[(r * 100) + nc] = Dist[distance] + cost
            if cost == 1:
                dq.append((r, nc))
            else:
                dq.appendleft((r, nc))

print(Dist[100*n+n])
