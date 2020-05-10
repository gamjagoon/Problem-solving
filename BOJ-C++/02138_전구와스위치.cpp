/*
Date : 02/01/2020
version : gcc 8.0.1 c++14
problem : 전구와 스위치
summary : 그리디
*/
#include <iostream>
#include <bitset>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;

int n,result = INT32_MAX;
bitset<100000>ans,now,state;

void view_bits(bitset<100000>&A){
	mfor(i,0,n-1)cout<<A[i];
	cout<<endl;
}

void push(int idx){
	if(idx > 0)now.flip(idx-1);
	now.flip(idx);
	if(idx < n - 1)now.flip(idx + 1);
}

void bfs(int idx, int cnt){
	if(idx == n-1){
		bool flag = true;
		mfor(i, 0, n-1){
			if(now[i] != ans[i]){
				flag = false;
				break;
			}
		}
		if(flag) {
			result = cnt > result ? result : cnt;
		}
		push(idx);
		cnt++;
		flag = true;
		mfor(i, 0, n-1){
			if(now[i] != ans[i]){
				flag = false;
				break;
			}
		}
		if(flag) {
			result = cnt > result ? result : cnt;
		}
		return;
	}
	if(ans[idx-1] == now[idx-1])bfs(idx+1, cnt);
	else{
		push(idx);
		if(ans[idx-1] == now[idx-1])bfs(idx+1, cnt+1);
		push(idx);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>state;
	cin>>ans;
	mfor(i,0,n-1)now[i] = state[i];
	bfs(1,0);
	mfor(i,0,n-1)now[i] = state[i];
	push(0);
	bfs(1,1);
	if(result == INT32_MAX)cout<<-1<<endl;
	else cout<<result<<endl;
	return 0;
}