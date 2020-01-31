import sys
read_L = sys.stdin.readline

def select(number, selected):
	global cnt

	if len(selected) == 3:
		cnt += 1
		return
	for i in range(number + 1, N + 1):
		if i not in selected:
			flag = 1

			for s in selected:
				if i in cant[s]:
					flag = 0
					break
			if flag:
				select(i, selected + [i])

if __name__ == '__main__':
	N, M = map(int, read_L().split())
	
	cnt = 0

	cant = {num: [] for num in range(1, N + 1)}
	
	for _ in range(M):
		a, b = map(int, read_L().split())

		cant[a].append(b)
		cant[b].append(a)

	for i in range(1, N + 1):
		select(i, [i])
		
	print (cnt)