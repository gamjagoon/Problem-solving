#include <iostream>
#include <cmath>
#include <deque>

using namespace std;

typedef long long ll;


int main() {ios::sync_with_stdio(false);cin.tie(0);
	int n,k;cin>>n>>k;
	ll prev = 1;
	ll cur = 10;
	int i = 1;
	while(1){
		if(prev <= k && k < cur)break;
		prev = cur;
		cur += (i + 1) * 9 * pow(10, i);
		i++;
	}
	int diff = k - prev;
	int cnt = diff/i;
	int pos = diff % i;
	int s = pow(10, i - 1);
	s += cnt;
	if( s > n ){
		cout<<-1<<endl;
	}else{
		deque<int>dq;
		while(s != 0 ){
			dq.push_front(s%10);
			s /= 10;
		}
		cout<<dq[pos]<<endl;
	}
}
