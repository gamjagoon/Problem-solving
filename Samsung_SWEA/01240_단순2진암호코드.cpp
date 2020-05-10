#include <iostream>
#define mfor(i,s,e) for(auto i = s; i <= e;++i)
using namespace std;

bool arr[50][100];

const int num[10] = {
	0b0001101,0b0011001,0b0010011,0b0111101,0b0100011,0b0110001,0b0101111,0b0111011,0b0110111,0b0001011
};

int sovle(){
	int N,M;
	cin>>N>>M;
	char a;
	mfor(i,0,N-1){
		mfor(j,0,M-1){
			cin>>a;
			if(a == '1'){
				arr[i][j] = true;
			}
			else{
				arr[i][j] = false;
			}
		}
	}
	int n = 0, idx = 1,res = 0,ret = 0,line = 0;
	while(1){
		bool flag = false;
		mfor(i,0,N-1){
			mfor(j,0,M-1){
				if(arr[i][j]){
					line = i;
					flag = true;
					break;
				}
			}
			if(flag)break;
		}
		if(flag)break;
	}
	while(n + 6< M-1){
		int tmp = 0;
		for(int s = n; s <= n+6; ++s){
			tmp<<=1;
			if(arr[line][s]){
				tmp++;
			}
		}
		n+=7;
		if(tmp != 0){
			mfor(i,0,9){
				if(num[i] == tmp){
					tmp = i;
					ret+= i;
					break;
				}
			}
			if(idx % 2 == 1){
				res+=tmp*3;
				idx++;
			}else{
				res+=tmp;
				idx++;
			}
		}
	}
	if(idx == 9 && res % 10 == 0){
		return ret;
	}else{
		return 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout<<"#"<<test_case<<' '<<sovle()<<'\n';
	}
	return 0;
}