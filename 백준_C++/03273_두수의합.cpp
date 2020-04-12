#include <iostream>
#include <vector>

using namespace std;

int arr[2000001];

int main() 
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n; cin>>n;
	while(n--){
		int m ;cin>>m;arr[m]+=1;
	}
	int o;cin>>o;
	int res = 0;
	int i = 1;
	while(i){
		if(i >= o - i )break;
		if(arr[i] > 0 && arr[o - i] > 0){
			res += arr[i] *arr[o-i];
		}i++;
	}
	cout<<res;
}
