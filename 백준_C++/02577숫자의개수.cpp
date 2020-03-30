#include <iostream>
using namespace std;
int cnt[10];

int main() {
	int mul,tmp;
	cin>>mul;
	cin>>tmp;
	mul *= tmp;
	cin>>tmp;
	mul*=tmp;
	int ch;
	while(mul != 0){
		ch = mul % 10;
		mul /= 10;
		cnt[ch]++;
	}
	for(int i = 0; i <= 9; i++){
		cout<<cnt[i]<<endl;
	}
}
