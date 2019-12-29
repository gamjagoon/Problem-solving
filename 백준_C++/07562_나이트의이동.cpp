#include <iostream>
#include <queue>
#define  r first
#define  c second
using namespace std;

const int dir[8][2] ={
	{-2,1},{-1,2},{1,2},{2,1},
	{2,-1},{1,-2},{-1,-2},{-2,-1}
};
typedef pair<int,int>p;

int main()
{
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		bool arr[303][303];
		int L,sr,sc,er,ec,cnt = 0;
		cin>>L>>sr>>sc>>er>>ec;
		for(int i = 0 ; i < L;++i){
			for(int j = 0 ; j < L;++j)
			{
				arr[i][j] = false;
			}
		}
		queue<p>q;
		q.push(make_pair(sr,sc));
		while(!q.empty())
		{
			int qsize = q.size();
			int nr,nc;
			bool f = false;
			for(int i = 0 ; i < qsize ; ++i)
			{
				nr = q.front().r;
				nc = q.front().c;
				q.pop();
				if(nr == er && nc == ec){
					cout<<cnt<<'\n';
					f = true;
					break;
				}
				int tr,tc;
				for(int i = 0; i < 8; ++i)
				{
					tr = nr + dir[i][0];
					tc = nc + dir[i][1];
					if(tr < 0 || tc < 0 || tr >= L || tc >= L||arr[tr][tc] == true)continue;
					arr[tr][tc] = true;
					q.push(make_pair(tr,tc));
				}
			}
			if(f) break;
			cnt++;
		}

	}
	return 0;
}