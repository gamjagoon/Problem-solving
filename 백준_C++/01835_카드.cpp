#include<iostream>
#include<deque>

using namespace std;
deque<int>q;

void solve(int N){
	q.push_front(N);
	for(int i = N-1; i >= 1; --i){
		q.push_front(i);
		int t = i;
		while(t--){
			q.push_front(q.back());
			q.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int N; cin>>N;
	if(N == 1){cout<<1;}
	else{
		solve(N);
		for(auto i : q){
			cout<<i<<' ';
		}
	}
}
