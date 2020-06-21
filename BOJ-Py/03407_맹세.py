import sys

M_set = set(["h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar",
             "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb",
             "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sn", "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "ti", "pb", "bi", "po", "at", "rn",
             "fr", "ra", "rf", "db", "sg", "bh", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "tb", "dy", "ho", "er", "tm", "yb", "lu",
             "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"])



def calc(S):
    flag = [True]
    flag.append(S[0] in M_set)

    if len(S) == 1:
        return flag[1]
    
    for i in range(2, len(S) + 1) :
        flag.append((flag[i-1] and (S[i-1] in M_set)) or (flag[i-2] and (S[i-2:i] in M_set)))
    
    return flag[len(S)]



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
