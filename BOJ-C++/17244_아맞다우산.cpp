#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global
typedef struct rc{
	int r,c,x = 0;
}rc;
int R,C;
rc S,E;
int xcnt = -1;
char arr[51][51];
int visit[51][51][1<<5];

int dir[4][2] ={1,0,-1,0,0,1,0,-1};
bool out_range(int r,int c){
	return r < 0 || c < 0 || r >= R || c >=C;
}

int bfs(){
	queue<rc>q;
	int X = 0;
	q.push({S.r,S.c,S.x});
	visit[S.r][S.c][X] = true;
	int t = 0;
	while(!q.empty()){
		int sz = q.size();
		while(sz--){
			rc f = q.front();q.pop();
			if(arr[f.r][f.c] == 'E' && f.x == (1 << xcnt) -1){
				return t;
			}
			for(int d = 0; d < 4; d++){
				int nr{f.r+dir[d][0]},nc{f.c+dir[d][1]},nx{f.x};
				if(out_range(nr,nc))continue;
				if(visit[nr][nc][nx])continue;
				char &nt = arr[nr][nc];
				if(nt == '#')continue;
				if(0<= nt && nt <= 4){
					nx |= (1 << nt);
				}
				visit[nr][nc][nx] = true;
				q.push({nr,nc,nx});
			}
		}
		t++;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>C>>R;
	string tmp;
	for(int r = 0; r < R;r++){
		cin>>tmp;
		for(int c = 0; c< C;c++){
			arr[r][c] = tmp[c];
			char &a = arr[r][c];
			if(a == 'X'){
				arr[r][c] = ++xcnt;
			}else if(a == 'S'){
				S=rc{r,c};
			}else if(a == 'E'){
				E=rc{r,c};
			}
		}
	}
	xcnt++;
	cout<<bfs()<<endl;
}
