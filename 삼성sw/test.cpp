#include <iostream>
using namespace std;

int main()
{
	int tmp = 0;
	for(int tc = 0;tc < 16;++tc)
	{
		tmp = tc;
		cout<<"Test "<<tc<<'\n';
		int chk[4] = {0,};
		int cnt = 0;
		for (int k = 0; k <= 3; k++)
		{
			cout<<k<<' '<<tmp<<'\n';
			while (tmp != 0 &&(tmp & 1) == (k & 1))
			{
				chk[k]++;
				tmp >>= 1;
			}
		}
		for(int i = 0 ; i <= 3;++i)
		{
			cout<<i<<" : "<<chk[i]<<'\n';
		}
	}
}