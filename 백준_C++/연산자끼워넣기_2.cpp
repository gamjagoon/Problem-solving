#include <iostream>
#include <cstdio>
#define endl '\n'
#define MAX 1000000000
#define MIN -1000000000

using namespace std;
int MX = MIN;
int MN = MAX;
int N;// number of input
int category[4] = {};//'+' '-' 'x' '/'
int numbers[11];
void view_arr(int arr[],int N){
	for(int i = 0 ; i < N; i++)
	{
			if(i%10 == 0)cout<<endl;
			cout<<"["<<arr[i]<<"] ";
	}
}

void dfs(int i, int sum,int p,int m,int mul,int di){
	if(i == N){
		MX = MX > sum ? MX:sum;
		MN = MN < sum ? MN:sum;
		return;
	}
		if(p!=0){
			dfs(i+1, sum+numbers[i],p-1,m,mul,di);
		}
		if(m!=0)
			dfs(i+1, sum-numbers[i],p,m-1,mul,di);
		if(mul!=0)	
			dfs(i+1, sum*numbers[i],p,m,mul-1,di);
		if(di!=0)
			dfs(i+1, sum/numbers[i],p,m,mul,di-1);
}

int main(){
	int idx;
	cin>>N;
	for(idx = 0 ; idx < N; idx++){cin>>numbers[idx];}
	for(idx = 0; idx < 4; idx++){cin>>category[idx];}
	int s = numbers[0];
	int a = category[0];
	int b = category[1];
	int c = category[2];
	int d = category[3];
	dfs(1,s,a,b,c,d);
	cout<<MX<<endl<<MN;
	return 0;
}

