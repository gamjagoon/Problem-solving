import sys
import math

def solve():
    while(True):
        L = list(map(int,sys.stdin.readline().split()))
        if(L[0] == 0):
            break
        N = L[0]
        S =sorted(L[1:len(L)])
        N_0 = S.count(0)
        m = N // 2 # 3 > 1 4 > 2 5 > 2
        n = N % 2 # 3 > 1 5 > 1
        NowPtr = 0
        rst = 0
        if(N_0):
            S = S[N_0:len(S)]
            for _ in range(N_0):
                S.insert(2,0)
        while(m >= 0):
            v = int(pow(10,m))
            while(n != 0):
                rst += S[NowPtr]*v
                NowPtr+=1
                n -= 1
            if(m != 0):
                n = 2
            m -= 1
        print(rst)




if __name__ == "__main__":
    solve()

