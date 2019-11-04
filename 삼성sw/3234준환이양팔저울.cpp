#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int test_case,N,result,total;
vector <int> v;
void dfs(int cnt,int l_sum,int r_sum,int visited){
	if( visited + 1 == 1<<N ){
		result += 1;
		return;
	}
	if(l_sum >= total - l_sum){
		int tmp = N - cnt;
		int facto = (int)pow(2,tmp);
		while(tmp > 1){
			facto*=tmp;
			tmp --;
		}
		result += facto;
		return;
	}
	for(int i = 0 ; i < N;++i){
		if( ( visited & (1<<i)) == 0){
			if(l_sum >= r_sum+v[i]){
				dfs(cnt+1,l_sum,r_sum+v[i],visited|(1<<i));
			}
			dfs(cnt+1,l_sum+v[i],r_sum,visited|(1<<i));
		}
	}	
	return;
}

int main(){
	scanf("%d",&test_case);
	int t_cnt = 1;
	while(test_case--){
		scanf("%d",&N);
		setbuf(stdout, NULL); 
		v.clear();
		v.reserve(9);
		result = 0;
		total = 0;
		for(int i = 0 ; i < N;++i){
			int ch;
			scanf("%d",&ch);
			v.push_back(ch);
			total += ch;
		}
		dfs(0,0,0,0);
		printf("#%d %d\n",t_cnt++,result);
	}
	return 0;
}