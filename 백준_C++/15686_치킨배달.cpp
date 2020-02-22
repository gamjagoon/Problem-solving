#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int,int>;

int map[51][51];
int N,M;
int hsize = 0,csize = 0;
int result = 100000;
//C , r
vector<pii >ck;
vector<pii >hm;
bool ch[13];
int d[13][100];
inline int sub(int a,int b){
	if(a > b)return a-b;
	else return b-a;
}

inline int distance(pii&a,pii&b){
	return sub(a.first,b.first)+sub(a.second,b.second);
}

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
	for(int i = 0 ; i < ck.size(); ++i){
		for(int j = 0; j < hm.size(); ++j){
			d[i][j] = distance(ck[i],hm[j]);
		}
	}
}

//집을 기준으로 모든 치킨집과의 비교
int best_ckdist(int j)
{
	int dist = 100;
	int tmp;
	//살아있는 치킨집에서 치킨거리를 구한다
	for(int i = 0 ; i < csize; ++i)
	{
		if(ch[i]){
			tmp = d[i][j];
			dist = tmp < dist ? tmp : dist;
		}
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
	ch[j] = true;
	dfs(n+1,j+1);
	ch[j] = false;
	dfs(n,j+1);
}

int main()
{
	init();
	dfs(0,0);
	cout<<result;
	return 0;
}