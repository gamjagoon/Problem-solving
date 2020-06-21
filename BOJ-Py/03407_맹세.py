import sys
from collections import deque

M_set = set(["h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar",
             "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb",
             "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sn", "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "ti", "pb", "bi", "po", "at", "rn",
             "fr", "ra", "rf", "db", "sg", "bh", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "tb", "dy", "ho", "er", "tm", "yb", "lu",
             "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"])



def calc(S):
    q = deque()
    Flag = False
    q.append(0)
    L = len(S)
    visit = [0 for i in range(L+1)]
    while len(q) != 0 :
        idx = q.popleft()
        if idx == L :
            Flag = True
            break
        tmp1 = S[idx]
        tmp2 = S[idx:idx+2]
        if tmp1 in M_set and visit[idx+1] == 0 :
            visit[idx+1] = 1
            q.append(idx+1)
        if tmp2 in M_set and visit[idx+2] == 0 :
            visit[idx+2] = 1 
            q.append(idx+2)
    
    return Flag



if __name__ == "__main__":
    n = int(sys.stdin.readline())
    while n:
        n -= 1
        S = sys.stdin.readline().rstrip()
        ret = calc(S)
        if ret:
            print("YES")
        else:
            print("NO")
