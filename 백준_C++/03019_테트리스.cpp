#include <iostream>
using namespace std;

int L,b, block[101],sol[101];

int cal_l(){
	int ret = 0,tmp;
	for(int i = 1; i <= L-3; ++i){
		if(sol[i] == 0 && sol[i+1] == 0&& sol[i+2]==0){
			ret++;
		}
	}
	return ret;
}

int cal_num(int n){
	int ret = 0;
	for(int i = 1; i <= L-1;++i){
		if(sol[i] == n){
			ret++;
		}
	}
	return ret;
}

int cal_two(int n1,int n2){
	int ret = 0;
	for(int i = 1; i <= L-2;++i){
		if(sol[i] == n1 && sol[i+1] == n2){
			ret++;
		}
	}
	return ret;
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>L>>b;
	for(int i = 1; i <= L; ++i){
		cin>>block[i];
		if(i >= 2){
			sol[i-1] = block[i] - block[i-1];
		}
	}
	int res = 0;
	switch (b)
	{
	case 1:
		res = L;
		if(L >= 4){
			res+=cal_l();
		}
		break;
	case 2:
		if(L >= 2)res+=cal_num(0);
		break;
	case 3:
		if(L>=2)res+=cal_num(-1);
		if(L>=3)res+=cal_two(0,1);
		break;
	case 4:
		if(L>=2)res+=cal_num(1);
		if(L>=3)res+=cal_two(-1,0);
		break;
	case 5:
		if(L>=2){
			res+=cal_num(1);
			res+=cal_num(-1);
		}
		if(L>=3){
			res+=cal_two(0,0);
			res+=cal_two(-1,1);
		}
		break;
	case 6:
		if(L >= 2){
			res+=cal_num(0);
			res+=cal_num(-2);
		}
		if(L>=3) {
			res+=cal_two(0,0);
			res+=cal_two(1,0);
		}
		break;
	default://!7
		if(L>=2)
		{
			res+=cal_num(0);
			res+=cal_num(2);
		}
		if(L >= 3)
		{
			res+=cal_two(0,0);
			res+=cal_two(0,-1);
		}
		break;
	}
	cout<<res;
	return 0;
}