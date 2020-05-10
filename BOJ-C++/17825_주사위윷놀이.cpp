/*
Date : 02/04/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/17825
summary : 구현문제
*/
#include <iostream>
#include <vector>
#include <map>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef map<int,int> yut;
typedef vector<pair<int,int> > vii;

yut R = {
	{0,2},{2,4},{4,6},{6,8},{8,10},{10,12},{12,14},{14, 16},{16, 18},{18, 20},{20, 22},{22, 24},{24, 26},{26, 28},{28, 30},{30, 32},{32, 34},{34, 36},{36, 38},{38, 40},{40, 50}
};
yut B = {
	{ 10, 13 },{ 13, 16 },{ 16, 19 },
	{ 19, 25 },{ 20, 22 },{ 22, 24 },
	{ 24, 25 },{ 30, 28 },{ 28, 27 },
	{ 27, 26 },{ 26, 25 },
};
yut B_goal = {
	{ 25, 30 },{ 30, 35 },{ 35, 40 },{ 40, 50 }
};
int dice[10];
int result = 0;
bool die[4];


void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	mfor(i,0,9){
		cin>>dice[i];
	}
}

int Cal_val(int idx,int mal,vii &position){
	int pos = position[mal].first;
	int dir = position[mal].second;
	int dice_num = dice[idx];

	if(pos == 50)return -1;

	mfor(j,0,dice_num-1){
		if(dir == 0)pos = R[pos];
		else if(dir == 1)pos = B[pos];
		else if(dir == 2)pos = B_goal[pos];

		if(pos == 25)dir = 2;
		else if(pos == 50)break;
	}

	if(pos == 50)position[mal].first = pos;
	else {
		if(dir == 0 && (pos == 10 || pos == 20 || pos == 30)){
			dir = 1;
		}
		bool flag = true;
		mfor(j,0,3){
			if(j != mal){
				if(position[j].first == pos && (pos == 40 || position[j].second == dir) ){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			position[mal].first = pos;
			position[mal].second = dir;
			return pos;
		}
		else{
			return -1;
		}
	}
	return 0;
}

void dfs(int idx,int val,vii &position){
	if(idx == 10){
		result = result < val ? val : result;
		return;
	}
	int pre_loc,pre_dir,new_val;
	mfor(i,0,3){
		pre_loc = position[i].first;
		pre_dir = position[i].second;
		new_val = Cal_val(idx,i,position);
		if(new_val > -1){
			dfs(idx + 1,val+new_val, position);
		}
		position[i].first = pre_loc;
		position[i].second = pre_dir;
	}

}



int main(){
	Input();
	vii position ={
		{0,0},{0,0},{0,0},{0,0}
	};
	dfs(0,0,position);
	cout<<result;
	return 0;
}