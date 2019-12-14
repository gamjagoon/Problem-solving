#include <iostream>
#include <vector>
using namespace std;
int N,L;
vector <int>col[100];
vector <int>raw[100];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>L;
	int tmp;
	for(int i = 0 ; i < N;++i)
	{
		for(int j = 0; j < N;++j)
		{
			cin>>tmp;
			col[i].push_back(tmp);
			raw[j].push_back(tmp);
		}
	}
}


bool ch_line(vector<int>&a)
{
	int vsz = a.size(),i = 0;
	int n_val, now;
	bool find = false;
	bool ch[vsz] = {false};
	while(!find)
	{
		if(i == vsz-1){
			find = true;
			break;
		}
		now = a[i];
		n_val = a[i + 1];
		if (n_val == now)
		{
			i++;
		}
		//내려감
		else if(now == n_val + 1){
			bool out = false;
			for (int j = 1; j <= L;++j)
			{
				if(i+j > vsz || a[i+j] !=n_val ||ch[j+i]){
					out = true;
					break;
				}
				else ch[j+i] = true;
			}
			if(out)
				break;
			else
				i += L ;
		}
		else if(now +1 == n_val){
			bool out = false;
			for (int j = 0; j < L;++j)
			{
				if(i-j < 0 || a[i-j] != now || ch[i-j]){
					out = true;
					break;
				}
				else ch[i - j] = true;
			}
			if(out)
				break;
			else
				i += 1;
		}
		else{
			break;
		}
	}
	return find;
}


int main()
{
	init();
	int cnt = 0;
	for(int i = 0 ; i < N;++i){
		if(ch_line(col[i])){
			cnt++;
		}
		if(ch_line(raw[i])){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}