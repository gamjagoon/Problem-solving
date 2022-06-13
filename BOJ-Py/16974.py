import sys

N, X = map(int, list(sys.stdin.readline().split()))
bugger_len = [1, 5]
petty_len = [1, 3]
l1_len = [0, 0, 1, 2, 3, 0]


def double_bugger(l_bugger):
    return l_bugger * 2 + 3


def double_petty(l_petty):
    return l_petty * 2 + 1


def find_ate_bugger(level, ate_num, petty_sum):
    if level == 0:
        return ate_num + petty_sum
    mid = bugger_len[level] // 2 + 1  # 5, 13, 29 => 3, 7, 15
    if ate_num == 1:
        return petty_sum
    elif ate_num < mid:
        return find_ate_bugger(level - 1, ate_num - 1, petty_sum)  # shrink problem
    elif ate_num == mid:
        return petty_len[level - 1] + 1 + petty_sum
    elif ate_num < bugger_len[level]:
        return find_ate_bugger(level - 1, ate_num - bugger_len[level - 1] - 2,
                               petty_sum + petty_len[level - 1] + 1)
    else:
        return petty_len[level] + petty_sum


for i in range(1, 51):
    bugger_len.append(double_bugger(bugger_len[i]))
    petty_len.append(double_petty(petty_len[i]))

print(find_ate_bugger(N, X, 0))
