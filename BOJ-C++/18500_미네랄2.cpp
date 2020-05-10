#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

typedef struct {
	int r,c;
}rc;

int R,C,N;
array<array<char, 101>,101>arr;
array<array<bool,101>, 101>ch;
int dir[4][2] = {1,0,-1,0,0,-1,0,1};
array<array<int, 101>, 101>level;
int level_num = 1;

template <typename T>
void view_map(array<array<T,101>,101>&arr){
	mfor(r,0,R){
		mfor(c,0,C){
			cout<<arr[r][c];
		}cout<<endl;
	}
}

template <typename T>
void init_array(array<array<T,101>,101>&arr, T v){
	mfor(r,0,R){
		mfor(c,0,C){
			arr[r][c] = v;
		}
	}
}

void shoot(bool left,int r){
	int c = left ? 1 : -1;
	int curr = left ? 0 : C-1;
	while(1){
		if(curr < 0 || curr >=C){
			return ;
		}
		if(arr[r][curr] == 'x'){
			arr[r][curr] = '.';
			return ;
		}
		curr += c;
	}
}

bool on_ground(void)
{
	init_array(ch, false);
	init_array(level, 0);
	level_num = 1;
	queue<rc>clu;
	for(int r = 0; r < R; ++r){
		for(int c = 0; c < C; ++c){
			if(arr[r][c] == 'x' && !ch[r][c]){
				bool gnd = false;
				rc S{r,c};
				ch[r][c] = true;
				clu.push(S);
				while(!clu.empty()){
					rc cur = clu.front();clu.pop();
					level[cur.r][cur.c] = level_num;
					if(cur.r == R - 1)gnd = true;
					for(int d = 0;d < 4;++d){
						rc next{cur.r+dir[d][0],cur.c+dir[d][1]};
						if(next.r < 0 || next.c < 0 || next.r >=R||next.c >=C || arr[next.r][next.c] == '.')continue;
						if(!ch[next.r][next.c]){
							ch[next.r][next.c] = true;
							clu.push(next);
						}
					}
				}
				if(!gnd){
					return false;
				}
				level_num++;
			}
		}
	}
	return true;
}

bool mineral_move(){
	for(int c = 0;c < C;++c){
		for(int r = R-1; r >= 0;--r){
			if(level[r][c] == level_num){
				if(r == R-1)return false;
				if( level[r+1][c] != level[r][c] && arr[r+1][c] == 'x')return false;
			}
		}
	}
	for (int c = 0; c < C; ++c) {
		for (int r = R - 1; r >= 0; --r) {
			if(level[r][c] == level_num)
			{
				arr[r+1][c] = arr[r][c];
				level[r+1][c] = level[r][c];
				arr[r][c] = '.';
			}
		}
	}
	return true;
}

int main() {
	io cin>>R>>C;
	string tmp;
	mfor(r,0,R)
	{
		cin>>tmp;
		mfor(c,0,C){
			arr[r][c] = tmp[c];
		}
	}
	cin>>N;
	bool left = true;
	mfor(i,0,N){
		int tmp;cin>>tmp;
		tmp = R - tmp;
		shoot(left,tmp);
		left = left ? false : true;
		if(!on_ground()){
			while(mineral_move());
		}
		
	}
	view_map(arr);
}
