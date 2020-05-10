/*
Date : 02/17/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/2268
summary : 
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)

using namespace std;
typedef long long ll;

ll tree[1025][1025], arr[1025][1025];
int N,M;

ll sum(int y,int x){
	int ans = 0;
	while(y > 0) {
		ans += tree[x][y];
		y -= (y & -y);
	}
	return ans;
}

void update(int r,int i,ll diff){
	while(i <= N){
		mfor(j,1,r){
			tree[j][i] += diff;
		}
		i += (i & -i);
	}
}

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	mfor(i,1,N){
		mfor(j,1,N){
			cin>>arr[i][j];
			update(i,j,arr[i][j]);
		}
	}
}

int main(){
	Input();
	int w;
	int x1,y1,x2,y2;
	int x,y,c;
	ll diff;
	while(M--){
		cin>>w;
		//x1, y1 부터 x2, y2 까지의 구간합 구하기
		if(w == 1){
			cin>>x1>>y1>>x2>>y2;
			cout<<sum(y2,x2)<<endl;
		}
		//x,y 를 c 로 바꾼다.
		else{
			cin>>x>>y>>c;
			diff = c - arr[x][y];
			arr[x][y] = c;
			update(x,y,diff);
		}
	}
}