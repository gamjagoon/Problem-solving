#include <iostream>
using namespace std;

int main()
{
	int C;
	cin>>C;
	int line = C*2 - 1;
	for(int i = 1; i <= C; ++i)
	{
		for(int j = C -i; j > 0; --j){
			cout<<' ';
		}
		for(int j = 0; j < i*2-1 ; ++j){
			cout<<'*';
		}
		cout<<'\n';
	}
}