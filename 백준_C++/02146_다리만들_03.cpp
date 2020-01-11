#include <iostream>
#include <queue>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef pair<int,int>p;

int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int map[100][100],brige[100][100];
int n,number = 0;

inline bool inrange(int r,int c){
	return r >= 0 && c >= 0 && r < n && c < n;
}

void view_arr(int a[][100]){
	mfor(i,0,n-1){
		mfor(j,0,n-1){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}cout<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	queue<p>b;
	cin>>n;
	mfor(i,0,n-1){
		mfor(j,0,n-1){
			cin>>map[i][j];
			if(map[i][j] == 1){
				map[i][j] = -1;
				b.push(p(i,j));
				brige[i][j] = 0;
			}
			else{
				brige[i][j] = -1;
				map[i][j] = 0;
			}
		}
	}
	queue<p> q;
	int r,c,nr,nc;
	mfor(i,0,n-1){
		mfor(j,0,n-1){
			if(map[i][j] == -1){
				number++;
				map[i][j] = number;
				q.push(p(i,j));
				while(!q.empty()){
					r = q.front().first;c = q.front().second;
					q.pop();
					mfor(k,0,3){
						nr = r + dir[k][1];
						nc = c + dir[k][0];
						if(inrange(nr,nc) && map[nr][nc] == -1){
							map[nr][nc] = number;
							q.push(p(nr,nc));
						}
					}
				}
			}
		}
	}
	while(!b.empty()){
		r = b.front().first, c = b.front().second;
		b.pop();
		mfor(k,0,3){
			nr = r + dir[k][0];
			nc = c + dir[k][1];
			if(inrange(nr,nc) && brige[nr][nc] == -1){
				map[nr][nc] = map[r][c];
				brige[nr][nc] = brige[r][c] + 1;
				b.push(p(nr,nc));
			}
		}
	}
	int result = 10000000;
	mfor(i,0,n-1){
		mfor(j,0,n-1){
			mfor(k,0,3){
				r = i + dir[k][0];
				c = j + dir[k][1];
				if(inrange(r,c) && map[i][j] != map[r][c]){
					if(brige[i][j] + brige[r][c] < result){
						result = brige[i][j] + brige[r][c];
					}
				}
			}
		}
	}
	cout<<result;
	return 0;
}