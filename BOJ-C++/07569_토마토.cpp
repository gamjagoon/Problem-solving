#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*0 r 1 c 2 h*/
int dir[6][3] = {-1,0,0,
				1,0,0,
				0,-1,0,
				0,1,0,
				0,0,1,
				0,0,-1};

typedef struct point{
	int r,c,h;
}p;

typedef struct layer
{
	bool ch[100][100];
}layer;

layer box[100];

int R,C,H,cnt = 0;
queue<p>tomato;

inline bool inrange(int r,int c,int h){
	return r>=0 && r < R && c>=0 && c < C && h>=0 && h < H;
}

int bfs()
{
	int res = -1,t = 0,sz,r,c,h,nr,nc,nh;
	while(!tomato.empty())
	{
		sz = tomato.size();
		if(cnt == 0)break;
		for(auto i = 0 ; i < sz; ++i){
			r = tomato.front().r;
			c = tomato.front().c;
			h = tomato.front().h;
			tomato.pop();
			for(int j = 0 ; j < 6; ++j){
				nr = r + dir[j][0];
				nc = c + dir[j][1];
				nh = h + dir[j][2];
				if(inrange(nr,nc,nh) && !box[nh].ch[nr][nc])
				{
					box[nh].ch[nr][nc] = true;
					cnt--;
					tomato.push(p{nr,nc,nh});
				}
			}
		}
		t++;
	}
	if(cnt == 0)return t;
	else return res;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>C>>R>>H;
	int tmp;
	for(int i = 0; i < H ; ++i){
		for(int j = 0 ; j < R; ++j){
			for(int k = 0; k < C; ++k){
				cin>>tmp;
				if(tmp == 0)
				{
					box[i].ch[j][k] = false;
					cnt++;
				}
				else{
					box[i].ch[j][k] = true;
					if(tmp == 1)
					{
						tomato.push(p{j,k,i});
					}
				}
			}
		}
	}
	if(cnt == 0)
		cout<<0;
	else 
		cout<<bfs();
	return 0;
}