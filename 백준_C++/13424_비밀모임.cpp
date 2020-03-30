#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define INF 987654321
using namespace std;

typedef struct valx{
	int val,x;
	
}valx;

struct cmp{
	bool operator()(valx a,valx b){
		if (a.val != b.val)return a.val > b.val;
		else return a.x < b.x;
	}
};

int N,M;
int dist[101][101];
int D[101];
bool ch[101];
vector<valx> g[101];
vector<int>fr;

void input() {
	cin>>N>>M;
	for(int i =1; i <= N; ++i){
		g[i].clear();
		for(int j = 1; j <= N; j++){
			dist[i][j] = INF;
		}
	}
	for(int a,b,v,i = 1; i <= M;i++){
		cin>>a>>b>>v;
		g[a].push_back({v,b});
		g[b].push_back({v,a});
	}
	int k; cin>>k;
	fr.clear();
	for(int tmp,i = 0; i < k; ++i){
		cin>>tmp;fr.push_back(tmp);
	}
	for(int i = 1; i <= N;i++){
		D[i] = 0;
		ch[i] = true;
	}
}



void die(int start){
	priority_queue<valx,vector<valx>,cmp>pq;
	pq.push({0,start}); dist[start][start] = 0;
	while(!pq.empty()){
		int now = pq.top().x;
		int cost = pq.top().val;
		pq.pop();
		if(cost > dist[start][now])continue;
		for(auto i : g[now]){
			int nxt = i.x;
			int ncost = cost + i.val;
			if(ncost < dist[start][nxt]){
				dist[start][nxt] = ncost;
				pq.push({ncost, nxt});
			}
		}
	}
}

int solve() {
	for(auto f : fr){
		die(f);
		for(int i = 1; i <= N; i++){
			D[i] += dist[f][i];
		}
	}
	int res;
    int ret = INF;
	for(int i = 1; i <= N;++i){
		if(ret > D[i]){
			ret = D[i];
			res = i;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		input();
		cout<<solve()<<endl;
	}
}

