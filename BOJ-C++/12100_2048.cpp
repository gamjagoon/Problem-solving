#include <iostream>
#include <vector>
using namespace std;
int map[21][21];
int ori_map[21][21];
int N, result = 0;
vector<int> A;

void swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N;++i)
	{
		for (int j = 0; j < N;++j)
		{
			cin >> map[i][j];
			ori_map[i][j] = map[i][j];
		}
	}
}

void view_map()
{
	for (int i = 0; i < N;++i)
	{
		for (int j = 0; j < N;++j)
		{
			cout << map[i][j]<<' ';
		}
		cout << '\n';
	}
}

void l_merge()
{
	int c = 0, r = 0, i = 0;
	bool flag = false;
	while(r < N)
	{
		if(c >= N){
			r++;
			i = 0;
			c = 0;
			flag = false;
			continue;
		}
		if(map[r][c] == 0){
			c++;
		}
		else if(flag && map[r][i] == map[r][c])
		{
			map[r][i] *= 2;
			map[r][c] = 0;
			i++;
			c++;
			flag = false;
		}
		else if(flag){
			i = c;
			c++;
		}
		else{
			i = c;
			c++;
			flag = true;
		}
	}
}
void u_merge()
{
	int nr = 0, nc = 0, i = 0;
	bool flag = false;
	while(nc < N)
	{
		if(nr >= N){
			nc++;
			i = 0;
			nr = 0;
			flag = false;
			continue;
		}
		if(map[nr][nc] == 0){
			nr++;
		}
		else if(flag && map[i][nc] == map[nr][nc])
		{
			map[i][nc] *= 2;
			map[nr][nc] = 0;
			i++;
			nr++;
			flag = false;
		}
		else if(flag){
			i = nr;
			nr++;
		}
		else{
			i = nr;
			nr++;
			flag = true;
		}
	}
}
void r_merge()
{
	int c = N-1, r = N-1, i = N-1;
	bool flag = false;
	while(r >= 0)
	{
		if(c < 0){
			r--;
			i = N-1;
			c = N-1;
			flag = false;
			continue;
		}
		if(map[r][c] == 0){
			c--;
		}
		else if(flag && map[r][i] == map[r][c])
		{
			map[r][i] *= 2;
			map[r][c] = 0;
			i--;
			c--;
			flag = false;
		}
		else if(flag){
			i = c;
			c--;
		}
		else{
			i = c;
			c--;
			flag = true;
		}
	}
}

void d_merge()
{
	int nr = N-1, nc = N-1, i = N-1;
	bool flag = false;
	while(nc >= 0)
	{
		if(nr < 0){
			nc--;
			i = N-1;
			nr = N-1;
			flag = false;
			continue;
		}
		if(map[nr][nc] == 0){
			nr--;
		}
		else if(flag && map[i][nc] == map[nr][nc])
		{
			map[i][nc] *= 2;
			map[nr][nc] = 0;
			i--;
			nr--;
			flag = false;
		}
		else if(flag){
			i = nr;
			nr--;
		}
		else{
			i = nr;
			nr--;
			flag = true;
		}
	}
}

void l_move()
{
	l_merge();
	for (int r = 0; r < N; ++r)
	{
		int last_find = 0;
		for (int c = 0; c < N;++c)
		{
			last_find = c + 1;
			if(last_find >= N)break;
			if(map[r][c] == 0)
			{
				for (; last_find < N;++last_find)
				{
					if(map[r][last_find] != 0)
					{
						swap(map[r][c], map[r][last_find]);
						break;
					}
				}
			}
		}
	}
}

void r_move()
{
	r_merge();
	for (int r = N-1; r >= 0; --r)
	{
		int last_find = N-1;
		for (int c = N-1; c >= 0;--c)
		{
			last_find = c - 1;
			if(last_find < 0)break;
			if(map[r][c] == 0)
			{
				for (; last_find >= 0;--last_find)
				{
					if(map[r][last_find] != 0)
					{
						swap(map[r][c], map[r][last_find]);
						break;
					}
				}
			}
		}
	}
}

void u_move()
{
	u_merge();
	for (int nc = 0; nc < N; ++nc)
	{
		int last_find = 0;
		for (int nr = 0; nr < N;++nr)
		{
			last_find = nr + 1;
			if(last_find >= N)break;
			if(map[nr][nc] == 0)
			{
				for (; last_find < N;++last_find)
				{
					if(map[last_find][nc] != 0)
					{
						swap(map[nr][nc], map[last_find][nc]);
						break;
					}
				}
			}
		}
	}
}

void d_move()
{
	d_merge();
	for (int nc = N-1; nc >= 0; --nc)
	{
		int last_find = N-1;
		for (int nr = N-1; nr >= 0;--nr)
		{
			last_find = nr - 1;
			if(last_find < 0)break;
			if(map[nr][nc] == 0)
			{
				for (; last_find >= 0;--last_find)
				{
					if(map[last_find][nc] != 0)
					{
						swap(map[nr][nc], map[last_find][nc]);
						break;
					}
				}
			}
		}
	}
}

void doit(int n)
{
	switch (n)
	{
	case 1:
		l_move();
		break;
	case 2:
		r_move();
		break;
	case 3:
		u_move();
		break;
	case 4:
		d_move();
		break;
	}
}

int solve(vector<int>&a)
{
	int res = 0;
	for(auto i : a)
	{
		doit(i);
	}
	for (int i = 0; i < N;++i)
	{
		for (int j = 0; j < N;++j)
		{
			if(map[i][j] > res)
			{
				res = map[i][j];
			}
			map[i][j] = ori_map[i][j];
		}
	}
	return res;
}

void dfs(int n)
{
	if(n == 5)
	{
		int tmp = solve(A);
		if(tmp > result){
			result = tmp;
		}
		return;
	}
	else
	{
		for (int i = 1; i < 5;++i)
		{
			A.push_back(i);
			dfs(n + 1);
			A.pop_back();
		}
	}
}

int main()
{
	input();
	dfs(0);
	cout << result;
	return 0;
}