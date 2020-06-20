import sys
line = sys.stdin.readline

N, M = map(int, line().split())
arr = list(line().strip().split())
check = [0 for _ in range(N)]
sub_arr = set()

arr = sorted(arr)
res = []

def dfs(sub_set='', cnt=0):
    if cnt == M-1:
        if sub_set not in sub_arr :
            res.append(sub_set)
            sub_arr.add(sub_set)
        return

    for i in range(N):
        if check[i] == 0:
            check[i] = 1
            dfs(sub_set+' {0}'.format(arr[i]), cnt+1)
            check[i] = 0


for i in range(N):
    if check[i] == 0:
        check[i] = 1
        dfs(arr[i], 0)
        check[i] = 0
        
for i in res:
    print(i)