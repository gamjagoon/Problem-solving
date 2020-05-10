#include <iostream>
using namespace std;
int memory[46] = {0,1,1};
int main(){
	int n;cin>>n;
	for(int i = 2;i<=n;++i){
		memory[i] = memory[i-1]+memory[i-2];
	}
	cout<<memory[n];
}