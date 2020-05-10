#include<iostream>
using namespace std;

int N,arr[11],resul = 0;
bool ch[11];

inline int mmax(int &a,int &b){
	return a > b? a: b;
}

int cal(int n){
	int pr = 0,fro = 0,i = n + 1;
	for(;i <= N; ++i){
		if(!ch[i]){
			fro = arr[i];
			break;
		}
	}
	i = n - 1;
	for(; i >= 1; --i){
		if(!ch[i]){
			pr = arr[i];
			break;
		}
	}
	return fro*pr;
}

void dfs(int n, int val){
	if(n == 2){
		resul = mmax(val, resul);
		return;
	}
	else{
		for(int i = 2; i < N; ++i){
			if(!ch[i]){
				ch[i] = true;
				dfs(n-1,val+cal(i));
				ch[i] = false;
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for(int i = 1; i <= N;i++){
		cin>>arr[i];
	}
	dfs(N,0);
	cout<<resul;
	return 0;
}