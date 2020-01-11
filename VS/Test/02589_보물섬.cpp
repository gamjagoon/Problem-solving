#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#define INF 100000000
using namespace std;
typedef struct P {
	int r,c,step;
}P;
vector<P>land[50];
int R,C,set_cnt = 0;
int map[50][50];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool inrange(int r, int c) {
	return r>= 0 && c >= 0 && r < R && c < C;
}
bool inrange(P &a) {
	return a.r >= 0 && a.c >= 0 && a.r < R && a.c < C;
}
void view_map() {
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j) {
			cout<<map[i][j]<<' ';
		}
		cout<<endl;
	}cout<<endl;
}

void fill_in(int r,int c) {
	if (inrange(r, c) && map[r][c] == -1) {
		land[set_cnt].push_back({ P{r,c} });
		map[r][c] = set_cnt;
		fill_in(r+1,c);
		fill_in(r,c+1);
		fill_in(r,c-1);
		fill_in(r-1,c);
	}
}
int calc(P start) {
	bool ch[50][50] ={false};
	int ret = 0;
	int val = map[start.r][start.c];
	queue<P>q;
	q.push(start);
	ch[start.r][start.c] = true;
	P tmp,ntmp;
	while (!q.empty()) {
		tmp = q.front();q.pop();
		if(ret < tmp.step)ret = tmp.step;
		for (int k = 0; k <= 3; ++k) {
			ntmp.r = tmp.r + dir[k][0];
			ntmp.c = tmp.c + dir[k][1];
			ntmp.step = tmp.step + 1;
			if (inrange(ntmp) && !ch[ntmp.r][ntmp.c] && map[ntmp.r][ntmp.c] == val) {
				ch[ntmp.r][ntmp.c] = true;
				q.push(ntmp);
			}
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>R>>C;
	string tmp;
	for (int i = 0; i <R; ++i) {
		cin>>tmp;
		for (int j = 0; j < C; ++j) {
			if (tmp[j] == 'L') {
				map[i][j] = -1;
			}
			else {
				map[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j)
		{
			if (map[i][j] == -1) {
				set_cnt++;
				land[set_cnt].push_back({P{i,j,0}});
				fill_in(i,j);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= set_cnt; ++i)
	{
		for (auto j : land[i]) {
			int tmp = calc(j);
			res = tmp > res ? tmp : res;
		}
	}
	cout<<res;
	return 0;
}