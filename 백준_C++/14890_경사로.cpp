#include <iostream>
#include <vector>
#include <cstring>
#define nfor(i,s,e) for(auto i = s; i < e; ++i)
using namespace std;
int N,L;
vector<int>col[101];
vector<int>raw[101];
bool ch[101]= {false};
void init()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N>>L;
	int tmp;
	nfor(i,0,N)
	{
		nfor(j,0,N){
			cin>>tmp;
			col[i].push_back(tmp);
			raw[j].push_back(tmp);
		}
	}
}
void ch_init()
{
	nfor(i,0,N)ch[i] = false;
}

//하나의 라인에서 가능성 찾기
bool calc_line(vector<int>&line,int now)
{
	if(now == N-1)return true;
	else{
		if(line[now] == line[now+1]){
			return calc_line(line,now+1);
		}
		else if(now+L < N && line[now] - line[now+1] == 1)
		{
			bool flag = true;
			for(int i = 2; i <= L;++i){
				if(line[now+i] != line[now+1]){
					flag = false;
					break;
				}
			}
			if(flag){
				for(int i = now+1; i <= now+L;++i){
					ch[i] = true;
				}
				return calc_line(line,now+L);
			}
		}
		else if(now-L+1 >= 0 && line[now] - line[now+1] == -1 && !ch[now]){
			bool flag = true;
			for(int i = 1; i <= L-1;++i){
				if(line[now-i] != line[now] || ch[now-i]){
					flag = false;
					break;
				}
			}
			if(flag)return calc_line(line,now+1);
		}
		return false;
	}
}

int main()
{
	init();
	int res = 0;
	nfor(i,0,N){
	ch_init();
		if(calc_line(col[i],0))res++;
	ch_init();
		if(calc_line(raw[i],0))res++;
	}
	cout<<res<<'\n';
	return 0;
}