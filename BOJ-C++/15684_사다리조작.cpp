#include <iostream>
using namespace std;

int N, M, H, cnt = 0;
int map[32][11] = {{0,},};
bool ch[32][11] = {false};
void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> H;
	for (int i = 0; i <= H;++i){
		for (int j = 1; j <= N;++j)
		{
			map[i][j] = j;
		}
	}
	int a, b;
	while(M--)
	{
		cin >> a >> b;
		ch[a][b] = true;
		ch[a][b+1] = true;
		map[a][b] = b + 1;
		map[a][b + 1] = b;
	}
}
void connect(int a, int b)
{
	map[a][b] = b + 1;
	map[a][b + 1] = b;
	ch[a][b] = true;
	ch[a][b+1] = true;
}
void disconnect(int a, int b)
{
	map[a][b] = b;
	map[a][b+1] = b + 1;
	ch[a][b] = false;
	ch[a][b+1] = false;
}

int find_EOL(int cal)
{
	int next_cal = map[1][cal];
	for (int h = 2; h <= H; ++h)
	{
		next_cal = map[h][next_cal];
	}
	return next_cal;
}
void init_ch()
{
	for (int i = 1; i <= H;++i){
		for (int j = 1; j <= N;++j)
		{
			ch[i][j] = false;
		}
	}
}

bool flag = false;
void dfs(int n,int v)
{
	if(n == v)
	{
		for (int i = 1; i <= N;++i)
		{
			if(i != find_EOL(i)){
				return;
			}
		}
		flag = true;
		cout << n;
		exit(0);
	}
	else
	{
		for (int h = 1; h <= H;++h)
		{
			for (int i = 1; i < N; ++i)
			{
				if(ch[h][i] || ch[h][i+1])
				{
					continue;
				}
				connect(h, i);
				dfs(n + 1, v);
				disconnect(h, i);
			}
		}
	}
}
int main()
{
	init();
	flag = true;
	for (int i = 1; i <= N;++i)
	{
		if(i != find_EOL(i)){
			flag = false;
			break;
		}
	}
	int k = 0;
	for (; k <= 3;++k)
	{
		dfs(0, k);
	}
	cout << "-1";
	return 0;
}