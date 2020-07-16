
/*
Date : 07/15/2020
version : gcc 9.2.0 c++17
problem : 
summary : set
*/
#include <iostream>
#include <unordered_set>
#define endl '\n'
using namespace std;

//Global
unordered_set<int>s;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int N, M,tmp;
	cin>>N;
	for (int i = 0; i < N; ++i) {
		cin>>tmp;
		s.insert(tmp);
	}
	cin>>M;
	for (int i = 0; i < M; ++i) {
		cin>>tmp;
		cout<<s.count(tmp)<<endl;
	}
}