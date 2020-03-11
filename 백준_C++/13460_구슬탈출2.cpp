#include <iostream>
using namespace std;

int main(){
	int level,pos;
	cin>>level>>pos;
	int track = 0;
	int M = 0;
	while(level != 1){
		++M;
		track<<=1;
		if(pos % 2 == 0){
			pos /= 2;
			track |= 1;
		}
		else {
			pos /= 2;
			pos +=1;
		}
		level--;
	}
	int cnt = 0;
	for(int i = 0 ; i < M; ++i){
		//now E
		if(track & 1)cnt++;
		track >>= 1;
	}
	if(cnt % 2==0){
		cout<<"Engineer\n";
    }
    else {
		cout<<"Doctor\n";
    }
}