#include <cstdio>
#include <vector>
using namespace std;


typedef struct{
	bool is_monster = false;
	bool check = false;
}arr;
arr a[15][15];
bool original[15][15];
int N,M,D;
int max_kill = 0;
int set[3];
bool Select[15]={};
int numbers[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};

int find_kill(int y,int x);
void DFS(int idx, int Cnt);
// void display_check(){
// 	printf("===========================\n");
// 	for(int i = 0;i < N;++i){
// 		for(int j = 0; j < M;++j){
// 		printf("%d ",a[i][j].check);
// 		}
// 		printf("     ");
// 		for(int j = 0; j < M;++j){
// 		printf("%d ",a[i][j].is_monster);
// 		}
// 		printf("\n");
// 	}
// 	printf("===========================\n");
// }
int sub(int a,int b){
	if(a>=b) return a-b;
	else return b-a;
}

int main(){
	scanf("%d %d %d",&N,&M,&D);
	//배열에 데이터 초기화
	for(int i = 0;i<N;++i){
		for(int j = 0;j<M;++j){
			scanf("%d",&a[i][j].is_monster);
			original[i][j] = a[i][j].is_monster;
		}
	}
	//아처의 처음 위치는 일단 몬스터 제일 아래 열  N열이다
	DFS(0,0);
	printf("%d",max_kill);
}
void DFS(int idx, int Cnt)
{
    if (Cnt == 3)
    {
		int index = 0,sum = 0;
		for(int i = 0;i<N;++i){
			for(int j = 0;j<M;++j){
				a[i][j].check = false;
				a[i][j].is_monster=original[i][j];
			}
		}
        for(int i = 0 ; i < M;++i){
			if(Select[i] == true){
				set[index++]=numbers[i];
			}
		}//set 에 궁수의 배치가 생성된다.


		for(int i = N;i >=1;--i){
			for(int j = i-1; j>=0;--j){
				for(int k = 0 ;k<M;++k){
					if(a[j][k].check == true){
						a[j][k].is_monster = false;
					}
				}
			}
			for(int j = 0; j < 3;++j){
			sum += find_kill(i,set[j]);
			}
			// printf("POSITION = %d\n",i);
			// printf("%d %d %d result = %d\n",set[0],set[1],set[2],sum);
			// display_check();
		}
		max_kill = max_kill > sum ? max_kill : sum;
		return;
    }
    for (int i = idx; i < M; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;

        DFS(i, Cnt + 1);
        Select[i] = false;
    }
}
/*
a배열에서 몬스터를 찾는다.
몬스터가 이미 체크됬으면 return 0
아니면 return 1 
*/
int find_kill(int y,int x){
	for(int d = 1;d <= D;++d)//D까지 탐색을 한다
	{
		int now_d = d-1;
		if(M < now_d){
			for(int j = 0;j<=M-1;++j){
				int b = sub(now_d,sub(j,x));
				if(y-1-b>=0){
					if(a[y-1-b][j].is_monster == true){
						if(a[y-1-b][j].check == false){
							a[y-1-b][j].check = true;
							return 1;
						}
						else{
							return 0;
						}
					}
				}
			}
			continue;
		}
		if(x-now_d >= 0 && x+now_d <= M-1){
			for(int j = x-now_d;j<=x+now_d;++j){
				int b = sub(now_d,sub(j,x));
				if(y-1-b>=0){
					// printf("D = %d x = %d  b = %d\n",d, j ,b);
					if(a[y-1-b][j].is_monster == true){
						if(a[y-1-b][j].check == false){
							a[y-1-b][j].check = true;
							return 1;
						}
						else{
							return 0;
						}
					}
				}
			}
			continue;
		}
		else if(x-now_d < 0){
			for(int j = 0;j<=x+now_d;++j){
				int b = sub(now_d,sub(j,x));
				if(y-1-b>=0){
					// printf("D = %d x = %d  b = %d\n",d, j ,b);
					if(a[y-1-b][j].is_monster == true){
						if(a[y-1-b][j].check == false){
							a[y-1-b][j].check = true;
							return 1;
						}
						else{
							return 0;
						}
					}
				}
			}
			continue;
		}
		else if(x+now_d > M-1){
			for(int j = x-now_d;j<=M-1;++j){
				int b = sub(now_d,sub(j,x));
				if(y-1-b>=0){
					// printf("D = %d x = %d  b = %d\n",d, j ,b);
					if(a[y-1-b][j].is_monster == true){
						if(a[y-1-b][j].check == false){
							a[y-1-b][j].check = true;
							return 1;
						}
						else{
							return 0;
						}
					}
				}
			}
			continue;
		}
		else{
			continue;
		}
	}
	return 0;
}