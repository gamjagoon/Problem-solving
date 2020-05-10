#include<iostream>
using namespace std;

int last = 1,first = 1 << 7,r_num = 1<<5,l_num = 2;
int N,K,nums[1001];
//톱니가 같으면 회전 안한다
void rotate(int n, int b){
	if(b == 1){
		int L = nums[n] & last;
		nums[n]>>=1;
		nums[n] |= L << 7;
	}
	else{
		int F = nums[n] & first;
		nums[n]<<=1;
		nums[n] |= F >> 7;
	}
}

bool inrange(int n){
	return n >= 1 && n <= N;
}

bool diff(int r, int l){
	int r_val = (nums[r] & r_num) >> 4;
	int l_val = (nums[l] & l_num);
	return r_val != l_val;
}

void right_doit(int a,int b){
	bool r = false;
	int rid = a + 1;
	if(inrange(rid) &&diff(a, rid)){
		r = true;
	}
	rotate(a, b);
	b *= -1;
	if(r)right_doit(rid, b);
}

void left_doit(int a,int b){
	bool l = false;int lid =a -1;
	if(inrange(lid) && diff(lid,a)){
		l = true;
	}
	rotate(a, b);
	b *= -1;
	if(l)left_doit(lid, b);
}


void doit(int a,int b)
{
	bool r = false,l = false;
	int rid = a+1,lid = a-1;
	if(inrange(rid) && diff(a,rid)){
		r = true;
	}
	if(inrange(lid) && diff(lid,a)){
		l = true;
	}
	rotate(a,b);
	b *= -1;
	if(r)right_doit(rid,b);
	if(l)left_doit(lid,b);
}

int cal(){
	int ret = 0;
	for(int i = 1; i <= N; ++i){
		if(nums[i] & first){
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
	cin>>N;
	string tmp;
	for(int i = 1; i <= N; ++i){
		cin>>tmp;
		int in = 0;
		for(int j = 0; j < 8; ++j){
			in<<=1;
			if(tmp[j] == '1'){
				in|=1;
			}
		}
		nums[i] = in;
	}
	cin>>K;
	int a,b;
	while(K--){
		cin>>a>>b;
		doit(a,b);
	}
	cout<<cal();
	return 0;
}