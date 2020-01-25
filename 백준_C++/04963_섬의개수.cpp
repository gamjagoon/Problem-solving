#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int C,cnt;
string arr[51];
typedef struct point{
	int r,c;
}p;

int dir[4][2] = {-1,0,1,0,0,1,0,-1};
int mcount[625];
void flood(p &a,int val){
	p tmp;
	for(int i = 0 ; i < 4; ++i){
		tmp.r = a.r + dir[i][0];
		tmp.c = a.c + dir[i][1];
		if(tmp.r >= 0 && tmp.r < C && tmp.c >= 0 && tmp.c < C && arr[tmp.r][tmp.c] == 0){
			arr[tmp.r][tmp.c] = val;
			mcount[val]++;
			flood(tmp, val);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	p tmp;
	queue<p>q;
	cin>>C;
	for(int i = 0 ; i < C; ++i){
		cin>>arr[i];
		for(int j = 0; j < C; ++j){
			if(arr[i][j] == '1'){
				q.push(p{i,j});
				arr[i][j] = 0;
			}
		}
	}
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		if(arr[tmp.r][tmp.c] == 0){
			cnt++;
			mcount[cnt]++;
			arr[tmp.r][tmp.c] = cnt;
			flood(tmp,cnt);
		}
	}
	sort(mcount+1,mcount+cnt+1);
	cout<<cnt<<endl;
	for(int i = 1 ; i <= cnt; ++i){
		cout<<mcount[i]<<'\n';
	}
	return 0;
}