#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global
int n,k;


int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	int t = 5;
	int num = 0;
	int cnt = 0;
	int N;
	int tmp = 1;
	while(t){
		while(num >= 1<<tmp){
			tmp++;
		}	
		for(int i = tmp-1 ; i >= 0; i--){
			if(num&1<<i)N = 1;
			else N = 0;
			cnt++;
			if(cnt == k){
				cout<<N<<' ';
				k+=n;
				t--;
				if(t == 0)break;
			}
		}
		num++;
	}
}
