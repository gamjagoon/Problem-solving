#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int arr[10][10];
int index = 1;
int paper[6] = {-1,5,5,5,5,5};
int prev_paper[6] = {-1,5,5,5,5,5};
int parent[10][10];
int element[101];
int cnt_elemet[101];
int cnt_result[101];
int result = 25;
int cnt;


void display();
void make_union(const int y,const int x);
void remove_square();
bool remove_rec(const int u,const int n);
bool view_cnt();
void find_first_element(int &x,int &y,int u);
void find_last_element(int &x,int &y,int u);
bool Inspection(int x,int y,int n,int u);
void func(int y, int x,int x_end,int y_end,int u);


int main(){
	for(int i = 0;i < 10;++i){
		for(int j = 0;j< 10;++j){
			scanf("%d",&arr[i][j]);
			if(arr[i][j] == 1)make_union(i,j);
		}
	}
	cnt = 0;
	remove_square();
	bool flag = true; 
	for(int i = 1; i < 6; ++i){
		if(paper[i] < 0){
			flag = false;
			break;
		}
	}
	if(!flag){
		printf("-1\n");
		return 0;
	}
	for(int i = 1 ; i < index;++i){
		if(element[i] != 0)
		{
			flag = false;
			break;
		}
	}
	if(flag){
		result = min(cnt,result);
		printf("%d",result);
	}
	else{
		for(int i = 1;i < index;++i){
			int x,y,x_end,y_end;
			if(element[i] != 0){
				find_first_element(x,y,i);
				find_last_element(x_end,y_end,i);
				func(y,x,x_end,y_end,i);
			}
		}
		result = cnt;
		int prev_result;
		for(int i = 1;i < index;++i)
		{
			if(element[i] != 0){
			printf("%d\n",cnt_result[i]);
			}
		}
		for(int i = 1;i < index;++i)
		{
			if(element[i] != 0){
				prev_result = result;
				result += cnt_result[i];
			}
			if(prev_result == result){
				printf("-1");
				return 0;
			}
		}
		printf("%d",result);
	}
	return 0;
}

void display(){
	printf("========================================\n");
	for(int i = 0;i < 10;++i){
		for(int j = 0;j< 10;++j){
			printf("%2d ",parent[i][j]);
		}
		printf("\n");
	}
}

void make_union(const int y,const int x){
	int key = index;
	if(y-1>=0 && parent[y-1][x] != 0){
		if(key > parent[y-1][x]){
			key = parent[y-1][x];
		}
		else{
			parent[y-1][x] = key;
		}
	}
	if(x-1>= 0 && parent[y][x-1] != 0){
		if(key > parent[y][x-1]){
			key = parent[y][x-1];
		}else{
			parent[y][x-1] = key;
		}
	}
	parent[y][x] = key;
	element[key]++;
	index++;
}
void remove_square(){
	for(int i = 1 ; i < index;++i){
		int n = element[i];
		if(n == 0)continue;
		switch(n){
			case 1:
			if(remove_rec(i,1)){
				element[i] = 0;
			}
			continue;
			case 4:
			if(remove_rec(i,2)){
				element[i] = 0;
			}
			continue;
			case 9:
			if(remove_rec(i,3)){
				element[i] = 0;
			}
			continue;
			case 16:
			if(remove_rec(i,4)){
				element[i] = 0;
			}
			continue;
			case 25:
			if(remove_rec(i,5)){
				element[i] = 0;
			}
			continue;
			default:
			continue;
		}
	}
}
void find_first_element(int &x,int &y,int u){
	bool find = false;
	for(int i = 0 ; i < 10;++i){
		for(int j = 0 ; j < 10;++j){
			if(parent[i][j] == u){
				x = j;
				y = i;
				find = true;
				break;
			}
		}
		if(find == true)break;
	}
	return;
}
void find_last_element(int &x,int &y,int u){
	bool find = false;
	for(int i = 9 ; i >=0;--i){
		for(int j = 9 ; j >= 0;--j){
			if(parent[i][j] == u){
				x = j;
				y = i;
				find = true;
				break;
			}
		}
		if(find == true)break;
	}
	return;
}
bool Inspection(int x,int y,int n,int u){
	if(parent[y + n - 1][x + n -1] != u)return false;
	if(parent[y + n - 1][x] != u)return false;
	if(parent[y][x + n - 1] != u)return false;
	for(int i = y;i < y+n;++i){
		for(int j = x;j < x+n;++j){
			if(parent[i][j] != u){
				return false;
			}
		}
	}
	return true;
}
bool remove_rec(const int u,const int n){
	int x,y;
	find_first_element(x,y,u);
	Inspection(x,y,n,u);
	for(int i = y;i < y+n;++i){
		for(int j = x;j < x+n;++j){
			parent[i][j] = 0;
		}
	}
	paper[n]-=1;
	prev_paper[n]-=1;
	cnt += 1;
	result -= 1;
	return true;
}

int good_n(int u){
	int loc = element[u];
	if(loc < 4)return 1;
	if(loc < 9)return 2;
	if(loc < 16)return 3;
	if(loc < 25)return 4;
	return 5;
}
void disp_prev_paper()
{
	printf("1:%d 2:%d 3:%d 4:%d 5:%d\n",prev_paper[1],prev_paper[2],prev_paper[3],prev_paper[4],prev_paper[5]);
}
void disp_paper()
{
	printf("1:%d 2:%d 3:%d 4:%d 5:%d\n",paper[1],paper[2],paper[3],paper[4],paper[5]);
}
/*시작지점과 종료지점 그리고 구하는 유니온을 선언
결과 배열에 저장*/
void func(int y, int x,int x_end,int y_end,int u)
{
	if (x == x_end+1)
	{
		func(y + 1, 0,x_end,y_end,u);
		return;
	}
	if (y == y_end+1)
	{
		for(int i = 1; i < 6;++i){
			if(prev_paper[i]-(5-paper[i]) < 0 )
			{
				return;
			}
		}
		for(int i = 1; i < 6;++i){
			prev_paper[i] = paper[i];
		}
		printf("after\n");
		result = min(cnt_elemet[u],result);
		cnt_result[u] = result;
		return;
	}
	if (parent[y][x] != u)
	{
		func(y, x + 1,x_end,y_end,u);
		return;
	}
	int a = good_n(u);
	// printf("a = %d\n",a);
	for (int n = a; n >= 1; n--)
	{
		if (paper[n] == 0 || y + n > 10 || x + n > 10)
		{
			continue;
		}
		if(!Inspection(x,y,n,u))continue;
		for (int j = y; j < y + n; j++)
		{
			for (int k = x; k < x + n; k++)
			{
				parent[j][k] = 0;
			}
		}
		paper[n]--;
		cnt_elemet[u]++;
		func(y, x + n,x_end,y_end,u);
		for (int j = y; j < y + n; j++)
		{
			for (int k = x; k < x + n; k++)
			{
				parent[j][k] = u;
			}
		}
		paper[n]++;
		cnt_elemet[u]--;
	}
}
