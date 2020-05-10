#include <iostream>
#include <queue>
using namespace std;

priority_queue<int>pq;
unsigned int arr[10001];
int N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	int tmp;
	for(int i = 0 ; i < N;++i){
		cin>>tmp;
		pq.push(tmp);
	}
	for(int i = 1; i <= N;++i){
		tmp = pq.top();
		pq.pop();
		arr[i] = tmp*i;
	}
	int Max = 0;
	for(int i = 1; i <= N;++i){
		if(Max < arr[i]){
			Max = arr[i];
		}
	}
	printf("%d",Max);
	return 0;
}