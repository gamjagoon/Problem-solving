#include <vector>
#include <stdio.h>

#define sub(a, b) a-b>0 ? a-b:b-a
using namespace std;
FILE* fp = fopen("output.txt", "w");
int N,M;
int D;
int arr[15][15];
int answer = 0;
struct arrs{
	int arr[15][15];
};
vector <arrs> p;
int set[3];
bool Select[15]={};
int numbers[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
int Live = 0;



int calc_arrs(){
	int a = set[0];
	int b = set[1];
	int c = set[2];
	int result = 0;
	fprintf(fp,"(%d %d %d)\n",a,b,c);
	for(int i=0;i<N;++i){
		for(int j = 0; j< M;++j){
			fprintf(fp,"[%d %d %d] ",p[a].arr[i][j],p[b].arr[i][j],p[c].arr[i][j]);
			if((p[a].arr[i][j] & p[b].arr[i][j] & p[c].arr[i][j]) == 1){
				result += 1;
			}
		}
		fprintf(fp,"\n");
	}
	return result;
}


bool find_obj(const int d,const int y, const int x){
	if(y-d<0){return false;}
	if (M - d < 0)
	{
		fprintf(fp,"%d %d %d: over\n",d,y,x);
		for(int i = 0;i<M;++i){
			int j = sub(i,x);
			if(p[x].arr[y-j-1][i] == 1){
				p[x].arr[y-j-1][i] = 0;
				return true;
			}
		}
	}
	else if(x-d >= 0 && x+d <= M-1){
		fprintf(fp,"%d %d %d: good\n",d,y,x);
		for(int i = x-d+1;i<=x+d-1;++i){
			int j = sub(i,x);
			if(p[x].arr[y-1-j][i] == 1){
				p[x].arr[y-1-j][i] = 0;
				return true;
			}
		}
	}
	else if(x-d < 0){
		fprintf(fp,"%d %d %d: left\n",d,y,x);
		for(int i = 0;i<=x+d-1;++i){
			int j = sub(i,x);
			if(p[x].arr[y-j-1][i] == 1){
				p[x].arr[y-j-1][i] = 0;
				return true;
			}
		}
	}
	else {
		fprintf(fp,"%d %d %d: right\n",d,y,x);
		for(int i = x-d+1;i<=M-1;++i){
			int j = sub(i,x);
			if(p[x].arr[y-1-j][i] == 1){
				p[x].arr[y-1-j][i] = 0;
				return true;
			}
		}
	}
	return false;
}

void DFS(int idx, int Cnt)
{
    if (Cnt == 3)
    {
		int index = 0,sum = Live;
        for(int i = 0 ; i < M;++i){
			if(Select[i] == true){
				set[index++]=numbers[i];
			}
		}

		int a = calc_arrs();
		fprintf(fp,"%d - %d = ",sum,a);
		sum = sum - a;
		fprintf(fp,"%d\n",sum);
		answer = sum > answer ? sum : answer; 
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

int main(){

	scanf("%d",&N);
	scanf("%d",&M);
	scanf("%d",&D);
	fill_n(Select,15,false);
	p.reserve(M);
	arrs a;
	p.reserve(M);
	for(int i = 0; i < N;++i){
		for(int j = 0 ; j < M;++j){
		scanf("%d",&a.arr[i][j]);
		Live+=a.arr[i][j];
		}
	}
	for(int i = 0; i < N;++i){
		arrs b(a);
		p.emplace_back(b);
	}

	for(int i = 0; i < M;++i){
		for(int h = N;h >= 1;--h){
			for(int j = 1;j<=D;++j){
				if(find_obj(j,h,i)==true){
					break;
				}
			}
		}
	}


	DFS(0,0);
	fprintf(fp,"%d",answer);
}