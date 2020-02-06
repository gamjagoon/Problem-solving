/*
Date : 02/05/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/17140
summary : 시뮬레이션
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
struct point{
	int val,cnt;
};
bool operator <(point a,point b){
	if(a.cnt == b.cnt){
		return a.val > b.val;
	}
	return a.cnt > b.cnt;
}
int R,C,K,rs,cs,result = 0;
int arr[101][101];
int ch[110];

void view_arr(int r,int c){
	mfor(i,1,r){
		mfor(j,1,c){
			cout<<arr[i][j]<<' ';
		}cout<<endl;
	}cout<<endl;
}

void Input(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C>>K;
	mfor(r,1,3)mfor(c,1,3)cin>>arr[r][c];
	rs = 3;
	cs = 3;
	mfor(i,0,109)ch[i]=0;
}
bool End(){
	if(arr[R][C] == K)return true;
	else return false;
}

priority_queue <point>q;

void Rcal(){
	int max_cs = 1;
	int v1,v2;
	mfor(r,1,rs){
		mfor(c,1,cs){
			ch[arr[r][c]]++;
		}
		mfor(i,1,109){
			if(ch[i] == 0)continue;
			q.push({i,ch[i]});
			ch[i] = 0;
		}
		int n_cs = 0;
		while(!q.empty()){
			n_cs+=2;
			if(n_cs > 100)break;
			v1 = q.top().val;
			v2 = q.top().cnt;
			q.pop();
			arr[r][n_cs-1] = v1;
			arr[r][n_cs] = v2;
			max_cs = n_cs > max_cs ? n_cs : max_cs;
		}
		while(!q.empty())q.pop();
		mfor(i,n_cs+1,cs){
			arr[r][i] = 0;
		}
	}
	cs = max_cs;
}

void Ccal(){
	int max_rs = 0;
	int v1,v2;
	mfor(c,1,cs){
		mfor(r,1,rs){
			ch[arr[r][c]]++;
		}
		mfor(i,1,109){
			if(ch[i] == 0)continue;
			q.push({i,ch[i]});
			ch[i] = 0;
		}
		int n_rs = 0;
		while(!q.empty()){
			n_rs+=2;
			if(n_rs > 100)break;
			v1 = q.top().val;
			v2 = q.top().cnt;
			q.pop();
			arr[n_rs-1][c] = v1;
			arr[n_rs][c] = v2;
			max_rs = n_rs > max_rs ? n_rs : max_rs;
		}
		while(!q.empty())q.pop();
		mfor(i,n_rs+1,rs){
			arr[i][c] = 0;
		}
	}
	rs = max_rs;
}

int main(){
	Input();
	while(!End()){
		result++;
		if(result > 100){
			result = -1;
			break;
		}
		if(rs >= cs)Rcal();
		else Ccal();
	}
	cout<<result;
	return 0;
}