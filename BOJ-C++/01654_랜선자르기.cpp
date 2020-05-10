#include <iostream>
#include <algorithm>
typedef long long ll;
ll n,k,left = 1,right = 0,lens[10000];

bool possible(ll N){
	ll ret = 0;
	for(int i = 0 ; i < k; ++i){
		ret += lens[i] / N;
	}
	if(ret >= n){
		return true;
	}
	else {
		return false;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>k>>n;
	for(int i = 0 ; i < k ; ++i){
		std::cin>>lens[i];
		right = right < lens[i] ? lens[i] : right;
	}
	while(left <= right){
		ll m = (right + left)>>1;
		if(possible(m)){//더 늘려라
			left = m + 1;
		}
		else {//줄여라
			right = m - 1;
		}
	}
	std::cout<<left - 1;
	return 0;
}