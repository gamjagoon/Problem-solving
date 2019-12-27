#include <cstdio>
#include <iostream>
using namespace std;

typedef pair<int, pair<int,int> > point_node_nodepoint;
/*
point | node , nodepoint
*/
point_node_nodepoint dice[4];
int turn[10];
//** point/10 - 1
int blue[4][8] = {
	{},
	{10, 13, 16, 19, 25, 30, 35, 40},
	{20, 22, 24, 25, 30, 35, 40, -1},
	{30, 28, 27, 26, 25, 30, 35, 40}
	};
int end_cnt = 0;
bool end_dice[4] = {false, false, false, false};
int result = 0;
void init()
{
	for (int i = 0; i < 10; ++i)
	{
		cin >> turn[i];
	}
	for (int i = 0; i < 4; ++i)
	{
		dice[i].first = 0;
		dice[i].second.first = 0;
		dice[i].second.second = 0;
	}
}

bool ch_dice(int point,int node)
{
	if(node == 0)
	{
		for (int i = 0; i < 4;++i)
		{
			if(dice[i].first == point && dice[i].second.first == 0)
				return false;
		}
		return true;
	}
	else{
		for (int i = 0; i < 4;++i)
		{
			if(dice[i].first == point && dice[i].second.first != 0){
				return false;
			}
		}
		return true;
	}
}
/*도착했으면 false 아니면 true*/
int move_dice(int dice_index,int k)
{
	int now_node = dice[dice_index].second.first;
	int now_point = dice[dice_index].first;
	int now_address = dice[dice_index].second.second;
	switch (now_node)
	{
	case 0:
		now_point += k * 2;
		if(!ch_dice(now_point,0))
			return -1;
		if(now_point > 40)
			now_point = -1;
		break;
	case 1:
		if(now_address + k < 8)
		{
			now_point = blue[1][now_address + k];
			if(!ch_dice(now_point,1))
				return -1;
			now_address += k;
		}
		else
			now_point = -1;
		break;
	case 2:
		if(now_address + k < 7)
		{
			now_point = blue[2][now_address + k];
			if(!ch_dice(now_point,2))
				return -1;
			now_address += k;
		}
		else
			now_point = -1;
		break;
	default:
		if(now_address + k < 8)
		{
			now_point = blue[3][now_address + k];
			if(!ch_dice(now_point,3))
				return -1;
			now_address += k;
		}
		else
			now_point = -1;
		break;
	}
	if(now_point == -1)//도착
	{
		end_cnt += 1;
		dice[dice_index].first = -1;
		return 0;
	}
	else if(now_node == 0){
		if(now_point % 10 == 0 && now_point / 10 != 4)
		{
			dice[dice_index].first = now_point;
			dice[dice_index].second.first = now_point / 10;
		}
		else{
			dice[dice_index].first = now_point;
		}
	}
	else{
		dice[dice_index].first = now_point;
		dice[dice_index].second.second = now_address;
	}
	return now_point;
}


void dfs(int n,int sum)
{
	if(n==10)
	{
		cout << "end" << sum << '\n';
		result = result > sum ? result : sum;
		return ;
	}
	else if(end_cnt == 4)
	{
		result = result > sum ? result : sum;
		return;
	}
	else
	{
		for (int i = 0; i < 4;++i)
		{
			if(end_dice[i])
				continue;
			int tmp = move_dice(i, turn[n]);
			if(tmp == -1)
			{
				cout << "dup\n";
				continue;
			}
			else if(tmp == 0){
				end_cnt++;
				end_dice[i] = true;
				cout <<n << '\t'<<sum<<'\t' << tmp << '\t' << i << '\n';
				for (int i = 0; i < 4; ++i){
					if(!end_dice[i])
						cout << i << " ";
				}
				cout << '\n';
				dfs(n + 1, sum);
				end_dice[i] = false;
				end_cnt--;
			}
			else{
				cout << n << '\t'<<sum<<'\t' << tmp << '\t' << i << '\n';
				dfs(n + 1, sum + tmp);
			}
		}
	}
}

int main()
{
	init();
	dfs(0,0);
	cout << result;
	return 0;
}