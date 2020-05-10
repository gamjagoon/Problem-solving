#include <string.h>
#include <stdio.h>
#define maxf 200000

int hashcode(char *str);
int add_data(int hash,char *key);
void unionfind(int hash_1,int hash_2);

int t_case,f_case,firsthash,secondhash;
int hashtable[maxf];
int groupsize[maxf];
int parent[maxf];
char namelist[maxf][21];
char firstbuf[21],secondbuf[21];
int index;



int main(){
	scanf("%d",&t_case);
	while(t_case--)
	{
		for(int i=0;i<maxf;i++){
        	hashtable[i]=-1;
        	parent[i]=-1;
   		}
		index = 0;//시작점
		scanf("%d",&f_case);
		for(int i = 0; i < f_case;++i){
			scanf("%s",firstbuf);
			scanf("%s",secondbuf);
			firsthash = add_data(hashcode(firstbuf),firstbuf);
			secondhash = add_data(hashcode(secondbuf),secondbuf);
			unionfind(firsthash,secondhash);
			int g_1 = groupsize[parent[hashtable[firsthash]]];
			int g_2 = groupsize[parent[hashtable[secondhash]]];
			if(g_1> g_2){
				printf("%d\n",g_1);
			}
			else{
				printf("%d\n",g_2);
			}
		}	
	}
}

int hashcode(char *str){
	int hash = 0;
	for(int i = 0;i < 3;++i){
		if(str[i] == 0)return hash;
		hash *= 26;
		hash += str[i];
	}
	return hash%maxf;
}

//문자열의 해쉬값을 해쉬테이블에 
int add_data(int hash,char *key){
	while(1){
		if(hashtable[hash] == -1){
			hashtable[hash] = index;
			parent[index] = index;
			strcpy(namelist[index],key);
			groupsize[index++] = 1;
			return hash;
		}
		else if(strcmp(namelist[hashtable[hash]],key)==0){
			return hash;
		}
		hash = (hash + 1) % maxf;
	}
}

int findparent(int idx){
	if(parent[idx] == idx){
		return idx;
	}
	else{
		return parent[idx] = findparent(parent[idx]);
	}
}

void unionfind(int hash_1,int hash_2){
	int idx_1 = hashtable[hash_1];
	int idx_2 = hashtable[hash_2];
	int parent_1 = findparent(idx_1);
	int parent_2 = findparent(idx_2);
	if(parent_1==parent_2)return;
	if(groupsize[parent_2] < groupsize[parent_1]){
        parent[parent_2]=parent_1;
        groupsize[parent_1]+=groupsize[parent_2];
    }
	else{
		parent[parent_1] = parent_2;
		groupsize[parent_2]+=groupsize[parent_1];
	}
}
