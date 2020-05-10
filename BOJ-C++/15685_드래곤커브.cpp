/*
Date : 02/05/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/15685
summary : 시뮬
*/
#include <iostream>
#include <vector>

using namespace std;
int N, r, c, d, g;
bool map[102][102] = {false};
//오 위 왼 아
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
vector<int> m_list[20];
void Input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i <= 101; ++i)
		for (int j = 0; j <= 101;++j)
			map[i][j] = false;
	for (int i = 0; i < N; ++i)
	{
		cin >> c >> r >> d >> g;
		map[r][c] = true;
		c += dir[d][0];
		r += dir[d][1];
		map[r][c] = true;
		m_list[i].push_back(d);
		for (int j = 0; j < g; ++j)
		{
			mark_dargon(i);
		}
	}
}

void mark_dargon(int n)
{
	int s = m_list[n].size();
	for (int i = s - 1; i >= 0; i--)
	{
		int tmp = (m_list[n][i] + 1) % 4;
		c += dir[tmp][0];
		r += dir[tmp][1];
		map[r][c] = true;
		m_list[n].push_back(tmp);
	}
}

int calc_result()
{
	int sum = 0;
	for (auto i = 0; i <= 101;++i)
	{
		for (auto j = 0; j <= 101; ++j)
		{
			if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
				sum++;
			}
		}
	}
	return sum;
}

int main()
{
	Input();
	cout << calc_result();
	return 0;
}