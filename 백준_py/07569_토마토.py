from sys import stdin
from collections import deque

C, R, H = map(int, stdin.readline().split())
box = [[[-1 for _ in range(C + 2)] for _ in range(R + 2)]]
for _ in range(H):
    tmp = [[-1 for _ in range(C + 2)]]
    for _ in range(R):
        line = [-1]
        line.extend([int(x) for x in stdin.readline().split()])
        line.append(-1)
        tmp.append(line)
    tmp.append([-1 for _ in range(C + 2)])
    box.append(tmp)
box.append([[-1 for _ in range(C + 2)] for _ in range(R + 2)])

###디큐에 초기조건 삽입

q = deque()
for c in range(1, C + 1):
    for r in range(1, R + 1):
        for h in range(1, H + 1):
            if box[h][r][c] == 1:
                q.append((h, r, c))

dir_r = [0, 0, 1, -1, 0, 0]
dir_c = [1, -1, 0, 0, 0, 0]
dir_h = [0, 0, 0, 0, 1, -1]

ans = 1
while q:
    # 먼저 넣은걸 뺀다
    h, r, c = q.pop()
    ans = box[h][r][c]
    for case in range(6):
        dh, dr, dc = dir_h[case], dir_r[case], dir_c[case]
        if box[h + dh][r + dr][c + dc] == 0:
            box[h + dh][r + dr][c + dc] = box[h][r][c] + 1
            q.append((h + dh, r + dr, c + dc))

ch_zero = True
for c in range(1, H + 1):
    for r in range(1, R + 1):
        if 0 in box[c][r]:
            print(-1)
            ch_zero = False
            break
    if not ch_zero:
        break
if ch_zero:
    print(ans - 1)
