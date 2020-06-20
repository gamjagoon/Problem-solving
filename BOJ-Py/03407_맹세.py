import sys


M_set = set(["h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar",
             "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb",
             "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sn", "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "ti", "pb", "bi", "po", "at", "rn",
             "fr", "ra", "rf", "db", "sg", "bh", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "tb", "dy", "ho", "er", "tm", "yb", "lu",
             "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"])


def calc(S, cur, end):
    if cur >= end:
        return True
    if S[cur] in M_set:
        return calc(S, cur+1, end)
    tmp = S[cur:cur+2]
    if tmp in M_set:
        return calc(S, cur+2, end)
    return False


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    while n:
        n -= 1
        S = sys.stdin.readline().rstrip()
        end = len(S)
        ret = calc(S, 0, len(S))
        if ret:
            print("YES")
        else:
            print("NO")
