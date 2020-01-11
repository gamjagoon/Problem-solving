#include <iostream>
#include <cstring>
using namespace std;

uint32_t w_mask[51];
int N,K;
uint32_t bt_mask[130];
bool ch[27];
int result = 0;
void init()
{
	for (int i = 'a'; i <= 'z'; ++i) {
		uint32_t ch = 1;
		bt_mask[i] = ch<<(i-'a');
	}
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N>>K;
	for (int i = 0; i < N; ++i) {
		w_mask[i] = 532741;
	}
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin>>tmp;
		for (auto j : tmp)
		{
			w_mask[i] |= bt_mask[j];
		}
	}
	for (int i = 0; i < 26; ++i) {
		ch[i] = false;
	}
	ch[0] = true;
	ch['c'-'a'] = true;
	ch['i'-'a'] = true;
	ch['t'-'a'] = true;
	ch['n'-'a'] = true;
}
void calc(uint32_t a)
{
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		if ((a | w_mask[i] )== a) {
			sum++;
		}
	}
	result = result > sum ? result : sum;
}
void dfs(int n,uint32_t a,int i)
{
	if (n == K) {
		calc(a);
		return;
	}
	else if(n+(26-i)<K)return;
	else
	{
		for (; i < 26; ++i)
		{
			if(ch[i]){
				continue;
			}
			else {
				ch[i] = true;
				dfs(n+1,a | 1<<i ,i+1);
				ch[i] = false;
			}
		}
		return;
	}
}

int main()
{
	init();
	if (K >= 5) {
		K-=5;
		dfs(0, (uint32_t)532741,0);
	}
	printf("%d",result);
	return 0;
}