#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

array<int,100001>arr;

int main() {

	ios::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	for(int i{0}; i< n; i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.begin()+n);
	int TT = 2000000;
	for(int i = 0 ; i <= n/2; i ++){
		TT = min(arr[i]+arr[n-i-1],TT);
	}
	cout<<TT;
}
