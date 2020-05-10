#include <iostream>
#include <queue>
using namespace std;
#define nfor(i,s,e) for(auto i = s; i < e; i++)
typedef struct {
	int r,c;
	bool albe;
}P;

P S,E;
int R,C;

int dir[4][2] ={{1,0},{-1,0},{0,-1},{0,1}};
int arr[1003][1003];
int dist[1003][1003][2];
bool out_range(int r,int c){
	return r <= 0 || c <= 0 || r > R|| c > C;
}

void bfs(){
	queue<P>q;
	S.albe = false;
	dist[S.r][S.c][0] = 1;
	q.push(S);
	int cnt = 0;
	while(!q.empty()) {
		cnt++;
		for(int size = q.size();size--;){
			P n = q.front();q.pop();	
			if(n.r == E.r && n.c == E.c){
				cout<<dist[n.r][n.c][n.albe]-1;return;
			}
			for(int r, c, i = 0; i < 4; ++i){
				r = n.r + dir[i][0];
				c = n.c + dir[i][1];
				if(out_range(r, c))continue;
				if(dist[r][c][n.albe])continue;
				if(arr[r][c] == 0){
					dist[r][c][n.albe] = dist[n.r][n.c][n.albe] + 1;
					q.push({r,c,n.albe});
				}
				if(arr[r][c] == 1 && n.albe==0){
					dist[r][c][1] = dist[n.r][n.c][0]+1;
					q.push({r,c,1});
				}
			}
		}
	}
	cout<<-1;
	return;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>R>>C;
	cin>>S.r>>S.c;
	cin>>E.r>>E.c;
	nfor(i,1,R+1){
		nfor(j,1,C+1){
			cin>>arr[i][j];
		}
	}
	bfs();
	return 0;
}
