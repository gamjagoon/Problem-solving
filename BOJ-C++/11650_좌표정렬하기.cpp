#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int x,y;
}point;

istream &operator >>(istream & in,point &a){
	in>>a.x>>a.y;
	return in;
}

ostream &operator <<(ostream& out,point &a){
	out<<a.x<<' '<<a.y;return out;
}
// 1000 1001 n+1
point P[100001];

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N;cin>>N;
	for(int i = 0 ; i < N; i++){
		cin>>P[i];		
	}
	// 1 2 3 4 5
	sort(P,P+N,[](point& a,point& b){if(a.x == b.x)return a.y < b.y;return a.x < b.x;});
	for(int i = 0 ; i < N; i++){
		cout<<P[i]<<'\n';
	}
}
