#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

queue<int>car_in;
int n,m,pos[10001],nowpos = 1,sz = 0;
ll cost[101],W[10001];
bool ch[101];

void input(){
	cin>>n>>m;
	for(int i = 1 ; i <= n; ++i){
		cin>>cost[i];
	}
	for(int i = 1; i <= m; ++i){
		cin>>W[i];
	}
	m*=2;
	sz = 0;
}
ll solve(){
	int tmp;
	ll ret = 0;
	while(m--){
		cin>>tmp;
		if(sz == n && tmp > 0){
			car_in.push(tmp);
		}
		else{
			if(tmp > 0){
				for(int i = 1; i <= n; ++i){
					if(!ch[i]){
						nowpos = i;
						break;
					}
				}
				ret += cost[nowpos] * W[tmp];
				ch[nowpos] = true;
				pos[tmp] = nowpos;
				sz++;
			}
			else{
				tmp*=-1;
				sz--;
				ch[pos[tmp]] = false;
				nowpos = pos[tmp];
				if(!car_in.empty()){
					tmp = car_in.front();
					car_in.pop();
					ret += cost[nowpos] * W[tmp];
					ch[nowpos] = true;
					pos[tmp] = nowpos;
					sz++;
				}
			}
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;cin>>tc;
	for(int i = 1; i<= tc; ++i)
	{
		input();
		cout<<'#'<<i<<' '<<solve()<<'\n';
	}
}