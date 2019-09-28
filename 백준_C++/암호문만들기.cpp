#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define WORDS_SIZE 16
#define endl '\n'
using namespace std;
//global
int R,C;
char words[WORDS_SIZE];
vector<char> dfs_vec;
set<char> moeum_set({'a','e','i','o','u'});
//swap func
template <typename T>
T M_swap(T &a, T &b){
	int temp = a;
	a = b;
	b = temp;
}
//sort func
void M_shell_Insertion_sort (char *arr){
	int len = 0;
	while(1){if(arr[++len]==0)break;} //length of string;
	int i, j , key , s;
	for(s = 0 ; s < len; s = 3*s + 1 );
	for(;s>0;s/=3){
		for(i = s; i < len; i++){ // 처음부터 정렬됬다 가정
			key = arr[i]; //키값을 arr[i] 부터
			j = i; //키값 바로 앞 인덱스
			while (j >= s && arr[j-s] > key)
			{
				arr[j] = arr[j-s]; 
				j -= s;
			}
			arr[j]= key;
		}
	}
}
//use dfs 
void dfs(int _depth, int _moeum_num, int _jaeum_num, int _start_idx){
	//return
	if( _depth == R - 1){
		if(_moeum_num < 1 || _jaeum_num < 2) return;
		for(int L_idx = 0;L_idx < R; L_idx++){
			cout<< dfs_vec[L_idx];
		}
		cout<<endl;
		return;
	}
	if(_start_idx >= C)return;
	if(R - (_moeum_num + _jaeum_num)>C - _start_idx)return;
	for(int c_idx = _start_idx; c_idx < C; c_idx++)
	{
		dfs_vec.emplace_back(words[c_idx]);
		if(moeum_set.find(words[c_idx])== moeum_set.end())
		{
			dfs(_depth + 1,_moeum_num,_jaeum_num +1,c_idx + 1);
		}
		else
		{
			dfs(_depth + 1, _moeum_num + 1, _jaeum_num, c_idx + 1);
		}
		dfs_vec.pop_back();
	}
}


int main(){
	cin>>R>>C;
	for (size_t i = 0; i < C; i++)
	{
		cin>>words[i];
	}
	M_shell_Insertion_sort(words);
	for(int c_idx = 0; c_idx < C; c_idx++)
	{
		dfs_vec.push_back(words[c_idx]);
		if(moeum_set.find(words[c_idx])== moeum_set.end())
			dfs(0, 0, 1, c_idx+1);
		else
			dfs(0,1,0,c_idx + 1);
		dfs_vec.pop_back();
	}
	
}