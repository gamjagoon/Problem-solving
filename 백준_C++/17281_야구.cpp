#include <cstdio>
#include <algorithm>
#define calc_num 0b1111
int man[50][10];
int test_case,base ,ch,result = 0;
int back_number[10] = {0,4,1,2,3,5,6,7,8,9};
int order [10];

void find_result();
bool next_permu(int s,int n);
int number(int a);

int main(){
    scanf("%d",&test_case);
    for(int i = 0;i < test_case;++i){
        for(int j = 1;j<=9;++j){
            scanf("%d",&man[i][j]);
        }
    }
	find_result();
    while(next_permu(2,10)){
	find_result();
    }
	printf("%d",result);
}
void find_result(){
	int score = 0;
	int current = 1;

    for(int t = 0; t < test_case;++t){
		int out = 0;
		int ground = 0;
		for(int k = 1;k < 10;++k){
			order[back_number[k]] = k;
		}
		while (out < 3)
		{
			int swing = man[t][order[current]];
			if (swing == 0)
			{
				++out;
			}
			else
			{
				ground = (ground + 1) << swing;
			}
			score += ((ground >> 4) & 1) + ((ground >> 5) & 1) + ((ground >> 6) & 1) + ((ground >> 7) & 1);
			ground &= 15;
			if (current == 9)
			{
				current = 1;
			}
			else
			{
				++current;
			}
		}
	}
	result = std::max(score,result);
}

bool next_permu(int s,int n){
	int i = n-1;
	while(i > s && back_number[i] <= back_number[i-1]) i-=1;
	if(i <= s)return false;
	int j = n-1;
	while( back_number[j] <= back_number[i-1])j--;
	int temp = back_number[i-1];
	back_number[i-1] = back_number[j];
	back_number[j] = temp;
	j = n-1;
	while(i<j){
		temp = back_number[i];
		back_number[i] = back_number[j];
		back_number[j] = temp;
		i++;j--;
	}
	return true;
}