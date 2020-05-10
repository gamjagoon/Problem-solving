#include<iostream>
#include <vector>
using namespace std;

int N,B,C;
long long cnt = 0;

int main()
{
	cin>>N;
	int tmp;
	vector<int>p(N);
	for(int i = 0 ; i < N;++i){
		cin>>p[i];
	}
	cin>>B>>C;
	int idx = 0;
	while(idx < N)
	{
		p[idx] -= B;
		cnt++;
		if(p[idx]>0)
		{
			if(p[idx] % C == 0) cnt += (p[idx]/C);
			else cnt += (p[idx]/C)+1;
		}
		idx++;
	}
	cout<<cnt;
	return 0;
}