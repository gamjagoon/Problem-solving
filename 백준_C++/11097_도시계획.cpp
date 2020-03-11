/*
Date : 02/29/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11097
summary : scc
*/
#include <iostream>
#include <vector>
#include <array>
#include <bitset>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

constexpr int Max = 301;

int N;
int main(){
	io
	int t;cin>>t;
	while(t--){
		cin>>N;
		bitset<Max> map[Max];
		mfor(i,0,N){
			string tmp;cin>>tmp;
			reverse(tmp.begin(),tmp.end());
			map[i] = bitset<Max>(tmp);
		}
		vector<pair<int,int> >edges;
		vector<bool>first(N,false), seen(N, false);
		mfor(i,0,N)if(!seen[i]){
			first[i] = true;
			seen[i] = true;
			int last = i;
			mfor(j,0,N)if(!seen[j] && map[i][j]&&map[j][i]){
				seen[j] = true;
				edges.push_back({last,j});
				last = j;
			}
			if(last != i)
				edges.push_back({last,i});
		}
		mfor(i,0, N)if(first[i]){
			mfor(j,0,N)if(first[j] && map[i][j] && i!=j){
				bool flag = true;
				mfor(k,0,N)if(first[k] && k != j && k != i){
					if(map[i][k]&&map[k][j]){
						flag = false;
					}
				}
				if(flag){
					edges.push_back({i,j});
				}
			}
		}
		cout<<edges.size()<<endl;
		for(auto i : edges){
			cout<<i.first+1<< ' '<<i.second+1<<endl;
		}
		cout<<endl;
	}
}