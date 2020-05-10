#include<iostream>
#include<algorithm>
using namespace std;

int arr[10000];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	int s,e;
	bool flag = false;
	for(s = n-1;s > 0; s--){
		if(arr[s] < arr[s-1]){
			flag = true;
			s--;
			break;
		}
	}
	if(flag){
		for(e = n-1; e > s; e--){
			if(arr[e] < arr[s]){
				swap(arr[e],arr[s]);
				break;
			}
		}
		int m = (n - s)/2;
		for(int i = 1; i <= m;++i){
			swap(arr[s+i],arr[n-i]);
		}
		for(int i = 0 ; i < n;++i){
			cout<<arr[i]<<' ';
		}
	}
	else{
		cout<<"-1";
	}
	return 0;
}