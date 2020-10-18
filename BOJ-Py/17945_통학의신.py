import sys,math

line = sys.stdin.readline
B, C = map(int, line().strip().split())
c = int(math.sqrt(B*B-C))
b_inv = B * -1
s = b_inv-c
b = b_inv+c
if(s == b):
    print(s)
else :
    print(s,b)