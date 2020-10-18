import sys
N, K =  map(int, sys.stdin.readline().split())
answer = 0
if(K >= 500000):
    while(N):
        N-=1
        g, x =  map(int, sys.stdin.readline().split())
        answer += g


else :
    X_arr = [ _ for _ in range(N)]
    while(N):
        N-=1
        X_arr[N]= list(map(int,sys.stdin.readline().split()))
    X = sorted(X_arr,key= lambda x: x[1])
    xs = X[0][0]
    xe = X[0][-1]
    print(X)

print(answer)
