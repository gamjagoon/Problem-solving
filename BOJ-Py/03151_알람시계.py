import math
import sys

  # a = [y, x]
  # b = [y, x]
def effort(a,b):
    return abs(a[0]-b[0])+abs(a[1]-b[1])

def correct(H,M,ori_H,ori_M):
    if(ori_M != M % 60):
        return False
    if(ori_H != H % 24):
        return False
    return True

def solve():
    h, m = map(int, sys.stdin.readline().split(":"))
    M = [[0 for c in range(3)] for i in range(4)]
    for a in range(3):
        for b in range(3):
            M[a][b] = a*3 + b + 1
    for a in range(3):
        M[3][a] = -1
    M[3][1] = 0
    L = [[0 for c in range(2)] for i in range(10)]
    for l in range(10):
        flag = False
        for a in range(4):
            if(flag):
                break
            for b in range(3):
                if(l == M[a][b]):
                    L[l] = [a,b]
                    flag = True
                    break
    D = {}
    for n10 in range(10):
        for n1 in range(10):
            num = n10 * 10 + n1
            D[num] = effort(L[n10],L[n1])
    DD = {}
    for H in range(100):
        for M in range(100):
            k = H * 100 + M
            v = D[H] + D[M] + D[(H%10)*10 + int(M/10)]
            DD[k] = v

    small = DD[h*100 + m]
    HH = h
    MM = m
    for H in range(100):
        for M in range(100):
            if(correct(H,M,h,m)):
                tmp = DD[H*100 + M]
                if (tmp < small):
                    HH = H
                    MM = M
                    small = tmp
                elif(tmp == small):
                    if(H > HH):
                        continue
                    if(M < MM):
                        HH = H
                        MM = M
    if(HH < 10):
        print('0',end='')
    print(HH,end='')
    print(":",end='')                                                                              
    if(MM<10):
        print('0',end='')
    print(MM,end='')

if __name__ == "__main__":
    solve()
