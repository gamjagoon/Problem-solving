#include <iostream>
#include <queue>
using namespace std;

const int16_t arr[10] = {
	0,0x1A0,0x1D0,0xC8,
	0x134,0xBA,0x59,
	0x26,0x17,0xB
};

int16_t  now_g;
int16_t input(){
	int16_t v = 0;
	char ch;
	for(int i = 0; i < 3;){
		ch = cin.get();
		if(ch == '*'){
			v++;
			v<<=1;
		}
		else if (ch =='.'){
			v<<=1;
		}
		else {
			i++;
			continue;
		}
	}
	v>>=1;
	return v;
}

int16_t bfs(int16_t ori_g){
	queue<int16_t>q;
	if(ori_g == 0){
		return 0;
	}
	bool ch[1<<9] = {false};
	q.push(ori_g);
	int result = 1;
	while(!q.empty())
	{
		auto qs = q.size();
		for(auto s = 0; s < qs; ++s)
		{
			int16_t g = q.front();
			q.pop();
			for(int16_t i = 1; i <= 9; ++i)
			{
				int16_t tmp = g^arr[i];
				if(!ch[tmp])
				{
					ch[tmp] = true;
					if(tmp == 0){
						return result;
					}
					q.push(tmp);
				}
			}
		}
		result++;
	}
}

int main()
{
	int16_t n = 0;
	cout << showbase;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	cin.get();
	int result = 0;
	while(n--)
	{
		now_g = input();
		result = bfs(now_g);
		cout << result<<'\n';
	}
}