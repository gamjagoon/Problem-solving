#include <iostream>
#define endl "\n"
using namespace std;
bool ch[1000001];
int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N,M;
	cin>>M>>N;
	ch[0] = true;
    ch[1] = true;
    for (int i = 2; i <= N; i++) {
        if (!ch[i]) {
            for (int j = 2 * i; j <= N; j += i)
                ch[j] = true;
        }
    }
    for(int i = M; i <= N; i++)
        if(!ch[i])
            cout << i << '\n';
}
