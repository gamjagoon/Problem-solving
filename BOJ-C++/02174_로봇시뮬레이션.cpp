#include <iostream>
#include <algorithm>
#include <array>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global
int R,C,N,M;
struct rot{
	int r,c;
	int dir;
};
int arr[102][102];
rot rlist[101];

void init() {
	cin>>C>>R>>N>>M;
	for(int i = 1; i <= N;i++){
		char d;
		cin>>rlist[i].c>>rlist[i].r;
		cin>>d;
		if(d == 'E')rlist[i].dir = 0;
		else if(d == 'S')rlist[i].dir = 1;
		else if(d == 'W')rlist[i].dir = 2;
		else if(d == 'N')rlist[i].dir = 3;
		arr[rlist[i].r][rlist[i].c] = i;
	}
}

//ESWN
int dir[4][2] = {
	0,1,-1,0,0,-1,1,0
};

bool outRange(int r,int c){
	return r <= 0 || r > R || c <= 0 || c > C;
}

void solve(){
	while(M--){
		int num,v;char order;
		cin>>num>>order>>v;
		if(order == 'F'){
			int r{rlist[num].r},c{rlist[num].c};
			int d{rlist[num].dir};
			for(int i = 0; i < v;i++){
				int nr = r + dir[d][0];
				int nc = c + dir[d][1];
				if(outRange(nr,nc)){
					cout<<"Robot "<<num<<" crashes into the wall\n";
					return;
				}
				if(arr[nr][nc] != 0){
					cout<<"Robot "<<num<<" crashes into robot "<<arr[nr][nc]<<'\n';
					return;
				}
				r = nr;
				c = nc;
			}
			arr[rlist[num].r][rlist[num].c] = 0;
			rlist[num].r = r;rlist[num].c = c;
			arr[rlist[num].r][rlist[num].c] = num;
		}else if(order == 'R'){
			v %= 4;
			rlist[num].dir = (rlist[num].dir + v) % 4;
		}// L
		else{
			v %= 4;
			if(rlist[num].dir - v < 0){
				rlist[num].dir = 4 - rlist[num].dir;
			}else{
				rlist[num].dir -= v;
			}
		}
	}
	cout<<"OK\n";
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	init();
	solve();
}
