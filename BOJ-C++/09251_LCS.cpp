#include <iostream>
using namespace std;

int Lmap[1001][1001] = {
	{
		0,
	},
};
string A, B;
int alen, blen;
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B;
	alen = A.length();
	blen = B.length();
	
	for (int i = 1; i <= alen;++i)
	{
		for (int j = 1; j <= blen;++j)
		{
			if(A[i-1] == B[j-1])
			{
				Lmap[i][j] = Lmap[i - 1][j - 1] + 1;
				if(ans < Lmap[i][j])
				{
					ans = Lmap[i][j];
				}
			}
			else{
				Lmap[i][j] = Lmap[i][j - 1] > Lmap[i - 1][j] ? Lmap[i][j - 1] : Lmap[i - 1][j];
			}
		}
	}
	cout << ans;
	return 0;
}