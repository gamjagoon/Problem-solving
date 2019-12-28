#include <iostream>
#include <cstring>
using namespace std;

int N, M, T = 0;
int id[501];
bool ch[501] = {false};

int root(int a)
{
	if(id[a] == a)
		return a;
	else
		return id[a] = root(id[a]);
}

void make_union(int p,int q)
{
	int i = root(p);
	int j = root(q);
	if(i == j || !ch[i] || !ch[j])
	{
		ch[i] = false;
		ch[j] = false;
	}
	id[j] = i;
}

int solve()
{
	int res = 0;
	for (int i = 1; i <= N;++i)
	{
		int tmp = root(i);
		if(ch[tmp])
		{
			ch[tmp] = false;
			res++;
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>N)
	{
		cin >> M;
		if(N == 0)
			return 0;
		T++;
		for (int i = 0; i <= N;++i)
		{
			id[i] = i;
			ch[i] = true;
		}
		int a, b;
		while(M--)
		{
			cin >> a >> b;
			if(a > b)
			{
				make_union(b, a);
			}
			else{
				make_union(a, b);
			}
		}
		int result = solve();
		if(result == 0)
		{
			cout << "Case " << T << ": No trees.\n";
		}
		else if(result == 1)
		{
			cout << "Case " << T << ": There is one tree.\n";
		}
		else{
			cout << "Case " << T << ": A forest of " << result << " trees.\n";
		}
	}
}