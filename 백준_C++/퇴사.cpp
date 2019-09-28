#include <iostream>
#include <cstdlib>
#define endl '\n'

/* intput 
	7		
	3 10
	5 20
	1 10
	1 20
	2 15
	4 40
	2 200 */
using namespace std;

int N,result = 0;
typedef struct{
	int Time;
	int Cash;
}Work;
Work **W;
void dfs(int day, int sum);
template<typename T>
T Max(T a, T b){
	return T (a > b) ?  a : b;
}
void Init(){
	int i ;
	cin >> N;
	W = (Work **)malloc((N) * sizeof(Work*));
	for( i = 0 ; i < N; i++){
		W[i] = (Work *)malloc( sizeof(Work));
	}
	for( i = 0 ; i < N; i++){
		cin>>W[i]->Time>>W[i]->Cash;
	}
}
//0에서 부터 시작
void My_dfs(int idx, int sum){
	if(idx == N)
	{ 
		result = Max(sum,result);
		return;
	}
	if(idx +W[idx]->Time <= N){
		My_dfs(idx+W[idx]->Time,sum+W[idx]->Cash); // 일을 한 경우
	}
	My_dfs(idx+1,sum); //일 안한 경우
	}
int main(){
	Init();
	My_dfs(0,0);
	//데이터 없에기;
	cout<<result<<endl;
	free(W);
	return 0;
}