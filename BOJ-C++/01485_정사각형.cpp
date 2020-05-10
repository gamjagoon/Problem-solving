#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global

typedef struct rc{
	long long r,c;
}rc;

long long D(rc &a,rc &b){
	return (a.r - b.r)*(a.r - b.r)+(a.c - b.c)*(a.c - b.c);
}

rc p[4];
long long tmp[6];

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int t; cin>>t;
	while (t--) {
		for(int i = 0; i < 4; i++){
			cin>>p[i].r>>p[i].c;
		}
		int k = 0;
		for(int i = 0 ; i < 4; i++){
			for(int j = i + 1; j < 4;j++)
			{
				tmp[k] = D(p[i],p[j]);
				k++;
			}
		}
		sort(tmp,tmp+6);
		if(tmp[0] == tmp[1] && tmp[1] == tmp[2] && tmp[2] == tmp[3] && tmp[4] == tmp[5]){
			cout<<1<<endl;
		}else cout<<0<<endl;
	}
}
