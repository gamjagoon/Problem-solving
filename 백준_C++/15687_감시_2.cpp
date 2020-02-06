/*
Date : 02/05/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/15683
summary : 구현, 완탐
*/
#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int dir[4][2] = {0,1,1,0,0,-1,-1,0};
int ori_arr[8][8];
int cal_arr[8][8];
int N,M;
int ori_blank = 0;
int result;

queue<pair<int,int> >mid_query;
vector<pair<int,pair<int,int> > >camera;
vector<int> v;

void Input(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	mfor(r,0,N-1){
		mfor(c,0,M-1){
			cin>>ori_arr[r][c];
			if(ori_arr[r][c] == 6)continue;
			else if(ori_arr[r][c] == 5){
				mid_query.push(make_pair(r,c));
			}
			else if(ori_arr[r][c] == 0 )ori_blank++;
			else camera.push_back(make_pair(ori_arr[r][c],make_pair(r,c)));
		}
	}
}

bool Out_range(int r,int c){
	if(r < 0 || c < 0|| r >= N || c >= M)return true;
	else {
		return false;
	}
}

int fill_blank(int r,int c,int d,int arr[][8]){
	if(arr[r][c] == 6)return 0;
	int ret = 0;
	if(arr[r][c] == 0){
		ret++;
		arr[r][c] = 7;
	}
	r+=dir[d][0];
	c+=dir[d][1];
	if(Out_range(r,c))return ret;
	return fill_blank(r,c,d,arr) + ret;
}

void Cal_Mid(){
	while(!mid_query.empty()){
		int r = mid_query.front().first;
		int c = mid_query.front().second;
		mid_query.pop();
		int nr,nc;
		mfor(d,0,3){
			nr = r + dir[d][0];
			nc = c + dir[d][1];
			if(!Out_range(nr,nc)){
				ori_blank -= fill_blank(nr,nc,d,ori_arr);
			}
		}
	}
	result = ori_blank;
}

void Solve(int n,int end){
	if(n == end){
		mfor(r,0,N-1){
			mfor(c,0,M-1){
				cal_arr[r][c] = ori_arr[r][c];
			}
		}
		int idx = 0;
		int r,c,num,nr,nc;
		int res = ori_blank,d;
		for(auto i : v){
			d = i;
			num = camera[idx].first;
			r = camera[idx].second.first;
			c = camera[idx].second.second;
			idx++;
			switch (num)
			{
			case 1:
				nr = r + dir[d][0];
				nc = c + dir[d][1];
				if(!Out_range(nr,nc)){
					res-= fill_blank(nr,nc,d,cal_arr);
				}
				break;
			case 2:
				nr = r + dir[d][0];
				nc = c + dir[d][1];
				if(!Out_range(nr,nc)){
					res-= fill_blank(nr,nc,d,cal_arr);
				}
				d += 2;
				d %= 4;
				nr = r + dir[d][0];
				nc = c + dir[d][1];
				if(!Out_range(nr,nc)){
					res-= fill_blank(nr,nc,d,cal_arr);
				}
				break;
			case 3:
				nr = r + dir[d][0];
				nc = c + dir[d][1];
				if(!Out_range(nr,nc)){
					res-= fill_blank(nr,nc,d,cal_arr);
				}
				d += 1;
				d %= 4;
				nr = r + dir[d][0];
				nc = c + dir[d][1];
				if(!Out_range(nr,nc)){
					res-= fill_blank(nr,nc,d,cal_arr);
				}
				break;
			case 4:
				nr = r + dir[d][0];
				nc = c + dir[d][1];
				if(!Out_range(nr,nc)){
					res-= fill_blank(nr,nc,d,cal_arr);
				}
				d += 1;
				d %= 4;
				nr = r + dir[d][0];
				nc = c + dir[d][1];
				if(!Out_range(nr,nc)){
					res-= fill_blank(nr,nc,d,cal_arr);
				}
				d += 1;
				d %= 4;
				nr = r + dir[d][0];
				nc = c + dir[d][1];
				if(!Out_range(nr,nc)){
					res-= fill_blank(nr,nc,d,cal_arr);
				}
				break;
			}
		}
		result = res < result ? res : result;
		return;
	}
	for(int d = 0; d < 4; ++d){
		v.push_back(d);
		Solve(n+1,end);
		v.pop_back();
	}
}

int main(){
	Input();
	Cal_Mid();
	int end = camera.size();
	Solve(0,end);
	cout<<result;
	return 0;
}