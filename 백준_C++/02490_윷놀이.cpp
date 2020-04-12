#include <iostream>

using namespace std;

char ch[]={'D','C','B','A','E'};

int main() {
	for(int t = 0; t <3; ++t){
		int num = 0,tmp;
		for(int i = 0; i < 4;i++){
			cin>>tmp;
			if(tmp)num++;

		}
		cout<<ch[num]<<'\n';
	}
}
