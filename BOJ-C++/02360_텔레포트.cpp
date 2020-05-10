#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

typedef vector<int> vi;

bool half(int n, int k) {
    return 2 * k >= (1 << n);
}

vi solve(int n, int k) {
    vi ret;
    if(n == 1 && k == 0) {
        ret.pb(1);
        return ret;
    }

    int sz;

    if(half(n, k)) {
        ret = solve(n, (1 << n) - k - 1);
        sz = ret.size();
        for(int i = 0; i < sz; i ++)
            ret[i] *= (-1);
        return ret;
    }

    vi prv = solve(n - 1, k);

    int shift = 1 << (n - 1);
    sz = shift - 1;

    if(half(n - 1, k)) {
        reverse(prv.begin(), prv.end());

        for(int i = 0; i < sz; i ++)
            prv[i] *= (-1);

        ret = prv;
        ret.pb(-shift);
        for(int i = 0; i < sz; i ++)
            if(prv[i] < 0) ret.pb(prv[i] - shift);
            else ret.pb(prv[i] + shift);
    }
    else {
        for(int i = 0; i < sz; i ++)
            if(prv[i] < 0) ret.pb(prv[i] - shift);
            else ret.pb(prv[i] + shift);

        ret.pb(-shift);
        for(int i = 0; i < sz; i ++)
            ret.pb(prv[i]);
    }

    return ret;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vi ans = solve(n, k);
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i ++) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}
