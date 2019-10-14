import sys

L, N = map(int, sys.stdin.readline().split())
rt_index = {}
rt_value = {}
a = ""
for i in range(N):
    a = sys.stdin.readline()
    if a in rt_index:
        del(rt_value[rt_index[a]])
        continue
    rt_index[a] = i
    rt_value[i] = a
for i in range(N):
    a = rt_value[i]
    if a:
        print(a)
