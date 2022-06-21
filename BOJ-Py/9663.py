arr = []
n = 0
res: int = 0


def horizon_check(cnt):
    for j in range(n):
        if arr[cnt][j] == 1:
            return False
    return True


def vertical_check(i):
    for j in range(0, n):
        if arr[j][i] == 1:
            return False
    return True


def across_check(i, j):
    a = i - j
    if a >= 0:
        sr = a
        sc = 0
    else:
        sr = 0
        sc = abs(a)
    for x in range(n-abs(a)):
        if arr[sr + x][sc + x] == 1:
            return False
    a = (n - 1) - i - j
    if a >= 0:
        sr = n - 1 - a
        sc = 0
    else:
        sr = n - 1
        sc = abs(a)
    for x in range(n-abs(a)):
        if arr[sr - x][sc + x] == 1:
            return False
    return True


def back(row):
    global res
    global arr
    if row == n:
        res += 1
        return
    else:
        for i in range(n):
            if arr[row][i] == 0 and vertical_check(i) and across_check(row, i):
                arr[row][i] = 1
                back(row + 1)
                arr[row][i] = 0


def view():
    for i in range(n):
        for j in range(n):
            print("{}".format(arr[i][j]), end="")
        print()
    print()


if __name__ == '__main__':
    n = int(input())
    arr = [[0 for _ in range(n)] for _ in range(n)]
    back(0)
    print(res)
