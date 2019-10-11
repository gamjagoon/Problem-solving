r, c = (map(int, input().split()))
now_sum = {}
hash_table = {}

for i in range(r):
    a = list(map(int, input().split()))
    for j in range(c):
        if j == 0:
            if i != 0:
                now_sum[(i, 0)] = now_sum[(i - 1, c - 1)] + a[0]
                continue
            else:
                now_sum[(i, 0)] = a[0]
                continue
        now_sum[(i, j)] = now_sum[(i, j - 1)] + a[j]

test_case = int(input())
buf = []
for _ in range(test_case):
    buf = list(map(int, input().split()))
    r_1, c_1, r_2, c_2 = buf[0] - 1, buf[1] - 1, buf[2] - 1, buf[3] - 1
    hash_int = 0
    for i in range(4):
        hash_int = hash_int * 100 + buf[i]
    hash_buf = str(hash_int)
    if hash_buf in hash_table:
        print(hash_table[hash_buf])
        continue
    result = 0
    for i in range(r_1, r_2 + 1):
        if c_1 == c_2:
            if c_1 != 0:
                result += now_sum[(i, c_1)] - now_sum[(i, c_1 - 1)]
            elif i > 0:
                result += now_sum[(i, c_1)] - now_sum[(i - 1, c - 1)]
            else:
                result += now_sum[(i, c_1)]
        else:
            if c_1 != 0:
                result += now_sum[(i, c_2)] - now_sum[(i, c_1 - 1)]
            elif i > 0:
                result += now_sum[(i, c_2)] - now_sum[(i - 1, c - 1)]
            else:
                result += now_sum[(i, c_2)]

    hash_table[hash_buf] = result
    print(result)
