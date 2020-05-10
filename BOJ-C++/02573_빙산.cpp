#include <iostream>
#include <queue>
#include <vector>
#define mp(r,c) make_pair(r,c)
#define mfor(a,b) for(int a = 0; a < b;++a)
using namespace std;
typedef pair<int,int> p;
int n,m,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}},cnt = 0;
int arr[301][301];
bool ch[301][301] = {false};
vector<p>lend;
queue<pair<p,int>>uplist;
void flood(int r,int c)
{
	queue<p>q;
	q.push(mp(r,c));
	ch[r][c] = true;
	cnt--;
	while (!q.empty())
	{
		r = q.front().first;
		c =q.front().second;
		q.pop();
		int d = 0;
		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (0 <= nr &&  0 <= nc &&  nr < n && nc < m)
			{
				if (arr[nr][nc] == 0)
				{
					d++;
					continue;
				}
				else if (!ch[nr][nc])
				{
					ch[nr][nc] = true;
					cnt--;
					q.push(mp(nr, nc));
				}
			}
		}
		uplist.push(mp(mp(r,c),d));
	}
}
bool update()
{
	p a;
	int v;
	while(!uplist.empty())
	{
		a = uplist.front().first;
		v = uplist.front().second;
		arr[a.first][a.second]-=v;
		if (arr[a.first][a.second] < 0) {
			arr[a.first][a.second] = 0;
		}
		uplist.pop();
	}
	for (auto i : lend)
	{
		if (arr[i.first][i.second] != 0) {
			ch[i.first][i.second] = false;
			cnt++;
		}
	}
	if(cnt == 0)
		return false;
	else 
		return true;
}
void view_map()
{
	mfor(i, n) {
		mfor(j, m) {
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}
	cout<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>arr[i][j];
			if (arr[i][j] != 0) {
				lend.push_back(mp(i,j));
				ch[i][j] = false;
				cnt++;
			}
			else {
				ch[i][j] = true;
			}
		}
	 }
	int result = 0;
	bool flag = false;
	while (!flag)
	{
		for (auto i : lend) {
			if (!ch[i.first][i.second]) {
				flood(i.first,i.second);
				if (cnt != 0) {
					flag = true;
					break;
				}
				else{
					if(!update()){
						result = 0;
						flag = true;
					};
					break;
				}
			}
		}
		if (!flag) {
			result++;
		}
	}
	cout<<result;
	return 0;
}