#include <iostream>
#include <vector>

using namespace std;

int map[51][51];
int N,M;
int hsize = 0,csize = 0;
int result = 100000;
//C , r
vector<pair<int,int> >ck;
vector<pair<int,int> >hm;
vector<int>alive;
void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M;
	for(int i = 1; i <= N;++i){
		for(int j = 1; j <= N;++j){
			cin>>map[i][j];
			if(map[i][j] == 2)
			{
				ck.push_back(make_pair(i,j) );
			}
			else if(map[i][j] == 1){
				hm.push_back(make_pair(i,j) );
			}
		}
	}
	hsize = hm.size();
	csize = ck.size();
}
inline int sub(int a,int b){
	if(a > b)return a-b;
	else return b-a;
}
inline int distance(int x,int y,int x2,int y2){
	return sub(x,x2)+sub(y,y2);
}
//집을 기준으로 모든 치킨집과의 비교
int best_ckdist(int n)
{
	int nc = hm[n].first;
	int nr = hm[n].second;
	int cc,cr;
	int dist = 100;
	for(auto i : alive)
	{
		cc = ck[i].first;
		cr = ck[i].second;
		int tmp = distance(nc,nr,cc,cr);
		dist = tmp < dist ? tmp : dist;
	}
	return dist;
}

void dfs(int n,int j)
{
	if(j > csize)return;
	if(n == M)
	{
		int sum =0;
		for(int i = 0 ; i < hsize;++i)
		{
			sum+= best_ckdist(i);
		}
		result = sum < result ? sum : result;
		return;
	}
	alive.push_back(j);
	dfs(n+1,j+1);
	alive.pop_back();
	dfs(n,j+1);
}

int main()
{
	init();
	dfs(0,0);
	cout<<result;
	return 0;
}