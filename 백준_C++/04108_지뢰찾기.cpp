/*
Date : 02/16/2020
version : gcc 6.3.0 c++14
problem : 
summary : 
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef pair<int,int> pii;

queue<pii>q;
int dir[8][2] ={
	1,-1,1,0,1,1,
	-1,-1,-1,0,-1,1,
	0,1,0,-1
};

char arr[100][100];

void Input(int r,int c){
	string tmp;
	mfor(i,0,r-1){
		cin>>tmp;
		mfor(j,0,c-1){
			if(tmp[j] == '.'){
				arr[i][j] = '0';
			}
			else{
				arr[i][j] = '*';
				q.push({i,j});
			}
		}
	}	
}

void update(int R,int C){
	int nr,nc,r,c;
	while(!q.empty()){
		r = q.front().first;
		c = q.front().second;
		q.pop();
		mfor(d,0,7){
			nr = r+ dir[d][0];
			nc = c + dir[d][1];
			if(nr >= 0 && nc >= 0 && nr < R && nc < C && arr[nr][nc] != '*'){
				arr[nr][nc] += 1;
			}
		}
	}
}

void print(int R,int C){
	mfor(i,0,R-1){
		mfor(j,0,C-1){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int a,b;
	while (cin>>a>>b)
	{
		if(a == 0 && b == 0)break;
		Input(a,b);
		update(a,b);
		print(a,b);
	}
	
}