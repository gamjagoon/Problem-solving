#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define INF 1000000000
using namespace std;
typedef pair<int,int>p;
int n;
bool map[102][102];


inline int sub(int a,int b){
	return a > b ? a - b: b - a;
}

inline int len(int x1,int x2,int y1,int y2)
{
	return sub(x1,x2) + sub(y1,y2);
}

void floyed()
{

	mfor(k,0,n+1){
		mfor(i,0,n+1){
			mfor(j,i,n+1){
				if(map[i][k] && map[k][j]){
					map[i][j] = true;
					map[j][i] = true;
				}
			}
		}
	}
}

void init()
{
	vector<p>in;
	cin>>n;
	in.resize(n+2);
	mfor(i,0,n+1){
		cin>>in[i].first>>in[i].second;
	}
	int d = 0;
	mfor(i,0,n+1){
		mfor(j,i,n+1){
			if(i == j)map[i][j] = 0;
			else{
				d = len(in[i].first,in[j].first,in[i].second,in[j].second);
				if(d > 1000){
					map[i][j] = false;
					map[j][i] = false;
				}
				else{
					map[i][j] = true;
					map[j][i] = true;
				}
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;cin>>t;
	while(t--)
	{
		init();
		floyed();
		if(map[0][n+1]){
			cout<<"happy"<<'\n';
		}
		else{
			cout<<"sad"<<'\n';
		}
	}
}