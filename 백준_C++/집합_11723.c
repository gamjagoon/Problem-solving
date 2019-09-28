#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int idx = 0;
int M;
int S[20];
char buffer[7];
int number;
char *order[6]={"check","add","remove","toggle","all","empty"};
int find(int a){
	if(idx == 0)return 0;
	for (int i = 0; i < idx; i++)
	{
		if(S[i] == a)return i;
	}
	return 0;
}
void _check(int a)
{
	if(find(a)){
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
	
}
void _add(int a){
	if(find(a)) return;
	else
	{
		S[idx++] = a;
		printf("idx = %d add %d\n",idx,S[idx-1]);
	}
}
void _remove(int a){
	int fp = find(a);
	printf("%d\n",fp);
	if(fp){
		S[fp] = 0;
		for(int i = fp;i<idx-1;i++){
			S[i] = S[i+1];
			idx --;
		}
	}
	else
	{
		return;
	}
}
void _toggle(char a){
	int fp = find(a);
	if(fp){
		S[fp] = 0;
		for(int i = fp;i<idx-1;i++){
			S[i] = S[i+1];
			idx --;
		}
	}
	else{
		S[idx] = a;
		idx++;
	}
}
void _all(){
	for(int i = 0;i<20;i++){
		S[i] = i+1;
	}
};
void _empty(){
	memset(S,0,20);
}

int main(){
	scanf("%d",&M);
	printf("%d\n",M);
	while(M!=0)
	{	
		memset(buffer,0,7);
		scanf("%s",buffer);
		for(int i = 0;i<6;i++)
		{
			if(strcmp(buffer,order[i])==0)
			{
				switch (i)
				{
				case 0:{
					scanf("%d",&number);
					M--;
					_check(number);
					break;}
				case 1:{
					scanf("%d",&number);
					M--;
					_add(number);
					break;}
				case 2:{
					scanf("%d",&number);
					M--;
					_remove(number);
					break;}
				case 3:{
					scanf("%d",&number);
					M--;
					_toggle(number);
					break;}
				case 4:{
					M--;
					_all();
					break;}
				default:
					M--;
					_empty();
					break;}
			}
		}
	}
}