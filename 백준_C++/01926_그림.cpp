/*
Date : 02/16/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/1926
summary : union_find
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int id[250010],sz[250010];
int arr[501][501];
int dir[4][2] = {
	1,0,-1,0,
	0,1,0,-1
};
int R,C,res = -1;

bool Out_range(int r,int c){
	return r <= 0 || c <= 0 || r > R|| c > C;
}

inline int to_idx(int r,int c){
	return c+C*(r-1);
}

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>R>>C;
	int tmp;
	mfor(r,1,R){
		mfor(c,1,C){
			cin>>arr[r][c];
			tmp = to_idx(r,c);
			id[tmp] = tmp;
			sz[tmp] = 1;
		}
	}
}

int root(int ch){
	if(id[ch] != ch){
		return id[ch] = root(id[ch]);
	}
	return ch;
}

void make_union(int a,int b){
	a = root(a);
	b = root(b);
	if(a == b)return;
	if(sz[a] >= sz[b]){
		id[b] = a;
		sz[a] += sz[b];
	}
	else{
		id[a] = b;
		sz[b] += sz[a];
	}
}

void cal(int r,int c){
	arr[r][c] = 0;
	int nr,nc;
	int p = to_idx(r,c);
	int q;
	mfor(d,0,3){
		nr = r + dir[d][0];
		nc = c + dir[d][1];
		if(!Out_range(nr,nc) && arr[nr][nc] == 1){
			q =to_idx(nr,nc);
			make_union(p,q);
			cal(nr,nc);
		}
	}
}

int main(){
	Input();
	int cnt=0;
	mfor(r,1,R){
		mfor(c,1,C){
			if(arr[r][c] == 1){
				cnt++;
				cal(r,c);
			}
		}
	}
	cout<<cnt<<endl;
	if(cnt == 0){
		cout<<0<<endl;
		return 0;
	}
	int End = to_idx(R,C);
	mfor(i,to_idx(1,1),End){
		res = res < sz[i] ? sz[i] : res;
	}
	cout<<res<<endl;
	return 0;
}