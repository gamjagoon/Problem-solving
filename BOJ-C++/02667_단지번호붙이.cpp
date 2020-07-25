#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int C,cnt = 1;
int arr[25][25];
int dir[4][2] = {-1,0,1,0,0,1,0,-1};
int mcount[625];

void bfs(int r,int c,int val){
  queue<pair<int,int>>q;
  q.push({r,c});
  int count = 0;
  arr[r][c] = val;
  count++;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int d = 0; d < 4;++d){
      int nr = x + dir[d][0];
      int nc = y + dir[d][1];
      if(nr < 0 || nc < 0|| nr >= C || nc >=C || arr[nr][nc] >= 0)continue;
      q.push({nr,nc});
      arr[nr][nc] = val;
      count++;
    }
  }
  mcount[val] = count;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>C;
	for(int i = 0 ; i < C; ++i){
    string tmp;cin>>tmp;
    for(int j = 0; j < C;++j){
      arr[i][j] = tmp[j] - '0';
      if(arr[i][j] == 1){
        arr[i][j] = -1;
      }
    }
	}
  for(int i = 0; i < C;++i){
    for(int j = 0; j < C;++j){
      if(arr[i][j] < 0){
        bfs(i,j,cnt);cnt++;
      }
    }
  }
  cnt--;
	sort(mcount+1,mcount+cnt+1);
	cout<<cnt<<endl;
	for(int i = 1 ; i <= cnt; ++i){
		cout<<mcount[i]<<'\n';
	}
	return 0;
}