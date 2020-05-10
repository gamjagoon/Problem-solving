#include <iostream>
#define mfor(i,s,e) for(auto i = s; i <= e;++i)
using namespace std;
int arr[101];
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	mfor(i, 0, n - 1) {
		cin>>arr[i];
	}
	int res = 0;
	for (int i = n - 2; i >= 0; --i)
	{
		if (arr[i] >= arr[i + 1])
		{
			res += arr[i] - arr[i+1] + 1;
			arr[i] = arr[i+1] - 1;
		}
	}
	cout<<res;
	return 0;
}