#include <iostream>

using namespace std;
int tile[31];
int main()
{
	int N;
	cin>>N;
	for(int i = 0 ; i < 31;++i){
		tile[i] = 0;
	}
	tile[0] = 1;
	tile[1] = 0;
	tile[2] = 3;
	if(N%2 == 1)cout<<0;
	else {
		int n = 2;
		while(N >= n){
			tile[n+2] = tile[n] * 3;
			cout<<tile[n]<<'\n';
			for(int i = n - 2; i >= 0; i -=2){
				tile[n+2] += tile[i]*2;
			}
			n+=2;
		}
	}
	return 0;
}