/*
Date : 05/01/2020
version : gcc 6.3.0 c++14
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

bool p[1000001];
vector<int>res;
vector<int>P;

void makeprime(int m){
	for(int i = 4; i <= m; i+=2){
		p[i] = true;
	}for(int i = 6; i <= m; i += 3){
		p[i] = true;
	}
	for(int i = 2; i <= m;i++){
		if(p[i])continue;
		for(int j = i*2; j <= m;j+=i){
			p[j] = true;
		}
	}
	for(int i = 2; i <= m; i++){
		if(!p[i]){
			P.push_back(i);
		}
	}
}

pair<int,int> findgold(int v){
	pair<int,int>ret{P[0],-1};
	int m = v / 2;
	for(auto i : P){
		if(i > m){
			break;
		}
		if(!p[v-i]){
			ret.first = i;
			ret.second = v-i;
			break;
		}
	}
	return ret;
}

int main(){
	io;
	int tmp;
	int M = 0;
	while(1){
		cin>>tmp;
		if(M < tmp)M = tmp;
		if(!tmp)break;
		else res.push_back(tmp);
	}
	makeprime(M);
	for(auto i : res){
		auto[a,b]=findgold(i);
		if(b < 0){
			cout << "Goldbach's conjecture is wrong.\n";
		}
		else{
			cout<<i<<" = "<<a<<" + "<<b<<endl;
		}
	}
}