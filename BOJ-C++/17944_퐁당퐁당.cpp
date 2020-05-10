#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define nfor(i,s,e) for(size_t i = s; i < e; ++i)
#define INF 1000000009
#define fio 
#define endl '\n'
using namespace std;
using pii = pair<int,int>;

//global
int arr[4000];


int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N,T;
	cin>>N>>T;
	int F = 4*N-2;
	for(int i=1; i <= 2*N; i++)arr[i] = i;
	int j = 2*N-1;
	for(int i = 2*N+1;i <= 4*N-2;i++){
		arr[i] = j--;
	}
	arr[0]=arr[4*N-2];
	cout<<arr[T%F];
}
