#include <iostream>
#include <queue>
#include <algorithm>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define INF 987654321
using namespace std;

typedef pair<int,int>p;

queue<p>b;
queue<p>q;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int map[10][10];
int dist[8][8];
int n,m,number = 0;
vector<pair<p,int>>v;

inline bool inrange(int r,int c){
	return 0 <= r && 0 <= c && r < n && c < m;
}

void view_map(int arr[][10]){
	mfor(i,0,n-1){
		mfor(j,0,m-1){
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}cout<<'\n';
	mfor(i,1,number){
		mfor(j,1,number){
			if(dist[i][j] == INF)cout<<"x ";
			else cout<<dist[i][j]<<' ';
		}
		cout<<'\n';
	}cout<<'\n';
}

void find_brige(int r,int c,int s,int k){
	int cnt = 0;
	int nr,nc;
	do{
		nr = r + dir[k][0];
		nc = c + dir[k][1];
		if(!inrange(nr,nc))return ;
		else{
			r = nr; c = nc;
			cnt++;
		}
	}while(map[r][c] == 0);
	if(cnt < 2)return;
	int e = map[nr][nc];
	if(dist[s][e] > cnt){
		dist[s][e] = cnt;
		dist[e][s] = cnt;
	}
	return;
}

bool compare(const pair<p,int>&a,const pair<p,int>&b){
	return a.second < b.second;
}
namespace uni{
	int id[8];

	int root(int i){
		if(id[i] != i){
			return id[i] = root(id[i]);
		}
		return i;
	}

	void init(){
		mfor(i,0,7){
			id[i] = i;
		}
	}

	void make_union(int p,int q)
	{
		p = root(p);
		q = root(q);
		if(p == q)return;
		if(p < q)id[q] = p;
		else id[p] = q;
	}

	bool find_root(int p,int q){
		p = root(p);
		q = root(q);
		if(p == q)return true;
		else return false;
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	mfor(i,0,n-1){
		mfor(j,0,m-1){
			cin>>map[i][j];
			if(map[i][j] == 1){
				map[i][j] = -1;
				b.push(p(i,j));
			}
			else{
				map[i][j] = 0;
			}
		}
	}
	int r,c,nr,nc;
	mfor(i,0,n-1){
		mfor(j,0,m-1){
			if(map[i][j] == -1){
				number++;
				q.push(p(i,j));
				map[i][j] = number;
				while(!q.empty()){
					r = q.front().first;
					c = q.front().second;
					q.pop();
					mfor(k,0,3){
						nr = r + dir[k][0];
						nc = c + dir[k][1];
						
						if(inrange(nr,nc) && map[nr][nc] == -1){
							map[nr][nc] = number;
							q.push(p(nr,nc));
						}
					}
				}
			}
		}
	}
	while(!q.empty())q.pop();
	mfor(i,1,number){
		mfor(j,1,number){
			if(i != j)dist[i][j] = INF;
			else dist[i][j] = 0;
		}
	}
	while(!b.empty()){
		r = b.front().first;
		c = b.front().second;
		b.pop();
		mfor(k,0,3){
			nr = r + dir[k][0];
			nc = c + dir[k][1];
			if(inrange(nr,nc) && map[nr][nc] == 0){
				find_brige(nr,nc,map[r][c],k);
			}
		}
	}
	uni::init();
	mfor(i,1,number){
		mfor(j,1,number)
		{
			if(dist[i][j] != INF && dist[i][j] != 0)
			{
				v.push_back(make_pair(p(i,j),dist[i][j]));
			}
		}
	}
	sort(v.begin(),v.end(),compare);
	uni::init();
	int res = 0;
	int cnt = 0;
	int sz = v.size();
	mfor(i,0,sz-1){
		if(!uni::find_root(v[i].first.first,v[i].first.second)){
			res+=v[i].second;
			uni::make_union(v[i].first.first,v[i].first.second);
			cnt++;
		}
	}
	if(cnt != number -1)cout<<-1;
	else cout<< res;
	return 0;
}