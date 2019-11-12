#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
//A = 0 ... Z = 25
int result = 0;
int str[50][27];

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	getchar();
	for(int i = 0; i < M;++i)
		memset(str[i],0,sizeof(str[i]));
	while(N--){
		int ch;
		for(int j = 0; j < M;++j){
			scanf("%1d",&ch);
			str[j][ch-'A']++;
		}
		getchar();
	}
	string tmp("");
	for(int i = 0 ; i < M;++i){
		int a = 0;
		int big = 0;
		int ch;
		for(int j = 0 ; j < 27;++j ){
			if(str[i][j] > big){
				big = str[i][j];
				ch = j;
			}
			a+=str[i][j];
		}
		a-=str[i][ch];
		result += a;
		tmp+=ch+'A';
	}
	cout<<tmp<<'\n';
	cout<<result<<'\n';
	return 0;

}