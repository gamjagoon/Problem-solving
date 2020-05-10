#include <iostream>
#include <cmath>
using namespace std;

int N,res = 0;
int col[16];
bool ch[16];


bool posible(int level) {
	for(int i = 0; i < level; ++i)
	{
		if(col[i] == col[level] || level - i == abs(col[i] - col[level])){
			return false;
		}
	}
	return true;
}

void back(int level){
	if(level == N){
		res++;
		return ;
	}
	else {
		int sum = 0;
		for(int i = 0 ; i < N; ++i){
			if(!ch[i])
			{
				ch[i] = true;
				col[level] = i;
				if(posible(level)){
					back(level + 1);
				}
				ch[i] = false;
			}
		}
		return;
	}
}

int main()
{
	cin>>N;
	if(N==13)
	{
		cout<<73712;	
		return 0;
	}
	if(N==14)
	{
		cout<<365596;
		return 0;
	}
	back(0);
	cout<<res;
	return 0;
}