#include <iostream>
#include <algorithm>
#include <cstdio>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global
int t = 3;
int anw[3];
void init() {
	for(int m = 0; m <=59; m++){
		int tmp = m/10 + m%10;
		for(int s = 0; s <= 59; s++){
			int res = tmp + s/10 + s%10;
			res %= 3;
			++anw[res];
		}
	}
	swap(anw[1],anw[2]);
}

int cal(int h1,int m1,int s1,int h2,int m2,int s2){
	int result = 0;
	if(h2 - h1 >= 2){
		for(int i = h1 +1 ; i < h2; i++){
			result += anw[i%3];
		}
	}
	if(h1 != h2){
		int loc = h1 % 3;if(loc != 0)loc = 3 - loc;
		for(int m = m1+1; m <=59;m++){
			int tmp = m % 10 + m /10;
			for(int s = 0; s <= 59;s++){
				int tmpp = tmp + s % 10 + s/ 10;
				if(tmpp % 3 == loc)++result;
			}
		}
		for(int s = s1; s <= 59; s++){
			int tmpp = m1 % 10 + m1 / 10 + s % 10 + s / 10;
			if(tmpp % 3 == loc)++result;
		}
		loc = h2 % 3; if(loc != 0)loc = 3 -loc;
		for(int m = m2-1; m >=0;--m){
			int tmp = m % 10 + m /10;
			for(int s = 59; s >= 0;--s){
				int tmpp = tmp + s % 10 + s/ 10;
				if(tmpp % 3 == loc)++result;
			}
		}
		for(int s = s2; s >= 0; --s){
			int tmpp = m2 % 10 + m2 / 10 + s % 10 + s / 10;
			if(tmpp % 3 == loc)++result;
		}
	}else if(m1 != m2){
		int loc = h1 % 3;if(loc != 0)loc = 3 - loc;
		for(int m = m1+1; m < m2;m++){
			int tmp = m % 10 + m /10;
			for(int s = 0; s <= 59;s++){
				int tmpp = tmp + s % 10 + s/ 10;
				if(tmpp % 3 == loc)++result;
			}
		}
		int tmp = m1 % 10 + m1 / 10;
		for(int s = s1; s <= 59; s++){
			int tmpp = tmp + s % 10 + s / 10;
			if(tmpp % 3 == loc)++result;
		}
		tmp = m2 % 10 + m2 / 10;
		for(int s = s2; s >= 0; --s){
			int tmpp = tmp + s % 10 + s / 10;
			if(tmpp % 3 == loc)++result;
		}
	}else if(s1 != s2){
		int loc = h1 % 3;if(loc != 0)loc = 3 - loc;
		int tmp = m1 % 10 + m1 / 10;
		for(int s = s1; s <= s2; s++){
			int tmpp = tmp + s % 10 + s / 10;
			if(tmpp % 3 == loc)++result;
		}
	}
	return result;
}

int main() {
	init();
	while(t--){
		int h1,h2,m1,m2,s1,s2,t1,t2;
		int result = 0;
		scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
		t1 = h1*10000+m1*100+s1;t2 = h2*10000+m2*100+s2;
		if(t1 < t2){
			result = cal(h1,m1,s1,h2,m2,s2); 
		}
		//구간 나누기
		else if(t1 > t2){
			result += cal(h1,m1,s1,23,59,59);
			result += cal(0,0,0,h2,m2,s2);
		}
		//같은 경우
		else{
			result = 0;
		}
		cout<<result<<'\n';
	}
}
