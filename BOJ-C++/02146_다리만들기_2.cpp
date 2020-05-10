#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef pair<int,int>p;

bool ch[100][100] = {0,};
int arr[100][100] = {0,};
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,set = 0;
int result = 987654321;

void flood(int r,int c,int num){
	if(r < 0 || n <= r || c < 0 || n <= c || arr[r][c] == 0)return;
	ch[r][c] = true;
	arr[r][c] = num;
	flood(r+1,c,num);
	flood(r,c+1,num);
	return;
}

int bfs(int num)
{
	int res = 0;
	queue<p>q;
	mfor(i,0,n-1)mfor(j,0,n-1){
		if(arr[i][j] == num){
			ch[i][j] = true;
			q.push(make_pair(i,j));
		}
	}

	while(!q.empty())
	{
		int qs = q.size();
		mfor(i,0,qs-1){
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			mfor(j,0,3){
				int nr = r + dir[j][0];
				int nc = c + dir[j][1];
				if(nr >= 0 && nc >= 0 && nr < n && nc < n)
				{
					if(arr[nr][nc] != 0 && arr[nr][nc] != num){
						return res;
					}
					else if(arr[nr][nc] == 0 && !ch[nr][nc]){
						ch[nr][nc] == true;
						q.push(make_pair(nr,nc));
					}
				}
			}
		}
		res++;
	}

}

void view_map()
{
	mfor(i,0,n-1){
		mfor(j,0,n-1){
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}cout<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	mfor(i,0,n-1){
		mfor(j,0,n-1){
			cin>>arr[i][j];
		}
	}
	mfor(i,0,n-1){
		mfor(j,0,n-1){
			if(arr[i][j] && !ch[i][j] ){
				set++;
				flood(i,j,set);
			}
		}
	}
	mfor(i,1,set-1){
		result = min(result,bfs(i));
		memset(ch,false,sizeof(ch));
	}
	cout<<result;
	return 0;
}