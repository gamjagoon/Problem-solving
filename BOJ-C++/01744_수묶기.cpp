#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>arr;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int N;cin>>N;
	if(N == 1){
		cin>>N;cout<<N;
		return 0;
	}
	int tmp;
	long long n = 0;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		cin>>tmp;
		if(tmp == 1){
			++n;
		}else if(tmp == 0){
			flag = true;
		}else {
			arr.push_back(tmp);
		}
	}
	sort(arr.begin(),arr.end());
	tmp = 0;
	int i = 0;
	int s = 0;
	N = arr.size();
	for(; i < N;i++){
		if(arr[i] > 0)break;
		if(s == 1){
			s = 0;
			n += tmp * arr[i];
			tmp = 0;
		}else {
			++s;
			tmp = arr[i];
		}
	}
	if(flag){
		tmp = 0;
	}
	n+=tmp;
	s = 0;
	int l = i;
	for(i = N-1;i >= l;i--){
		if(s == 1){
			s = 0;
			n += tmp * arr[i];
			tmp = 0;
		}else {
			++s;
			tmp = arr[i];
		}
	}
	if(s)n += tmp;
	cout<<n;
}
