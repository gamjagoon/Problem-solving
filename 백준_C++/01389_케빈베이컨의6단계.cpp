#include <iostream>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define INF 100000000
using namespace std;

int node[101][101];
int result[101];
int main()
{
	int n,m;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	mfor(i,1,n){
		result[i] = 0;
		mfor(j,i,n){
			if(i == j)node[i][j] = 0;
			else {
				node[i][j] = INF;
				node[j][i] = INF;
			}
		}
	}
	int a,b;
	while(m--){
		cin>>a>>b;
		node[a][b] = 1;
		node[b][a] = 1;
	}
	int tmp;
	mfor(k,1,n){
		mfor(i,1,n){
			mfor(j,i+1,n){
				tmp = node[i][k] + node[k][j];
				if(node[i][j] > tmp){
					node[i][j] = tmp;
					node[j][i] = tmp;
				}
			}
		}
	}

	int val = INF;
	int num = 0;
	mfor(i,1,n){
		mfor(j,i+1,n){
			if(node[i][j] < INF){
				result[i] += node[i][j];
				result[j] += node[i][j];
			}
		}
	}
	mfor(i,1,n){
		if(result[i] < val){
			val = result[i];
			num = i;
		}
	}
	cout<<num;
	return 0;
}