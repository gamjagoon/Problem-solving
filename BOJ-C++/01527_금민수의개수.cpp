#include <iostream>
#define endl '\n'
using namespace std;

long long dfs(long long N,long long cnt,long long end,long long val){
	if(cnt > 10)return 0;
	if(val > end)return 0;
	int ret = 0;
	if(val >= N){
		ret++;
	}
	val *= 10;
	ret += dfs(N,cnt+1,end,val+4);
	ret += dfs(N,cnt+1,end,val+7);
	return ret;
}

int main() {
	long long A,B;
	cin>>A>>B;
	cout<<dfs(A,0,B,0);
}
