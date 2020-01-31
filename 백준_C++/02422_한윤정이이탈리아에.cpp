#include <iostream>
#include <vector>
using namespace std;

bool map[201][201];
vector<int>in;
int N,M;

int dfs(int cnt,int num){
	if(cnt == 3){
		return 1;
	}
	else {
		int S = 0;
		bool flag = true;
		for(int i = num + 1; i <= N;++i){
			if(!map[num][i]){
				flag = true;
				for(int j = 0 ; j < cnt - 1;++j){
					if(map[in[j]][i]){
						flag = false;
						break;
					}
				}
				if(!flag)continue;
				in.push_back(i);
				S += dfs(cnt+1,i);
				in.pop_back();
			}
		}
		return S;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	int a,b;
	for(int i  = 0 ; i < M; ++i){
		cin>>a>>b;
		map[a][b] = true;
		map[b][a] = true;
	}
	int res = 0;
	for(int i = 1; i <= N-2; ++i)
	{
		in.push_back(i);
		res += dfs(1,i);
		in.pop_back();
	}
	cout<<res;
	return 0;
}