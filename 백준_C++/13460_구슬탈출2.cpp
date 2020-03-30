#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#define endl '\n'
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

set<int>global;

typedef struct rc{
	int r,c;
	rc &operator=(const rc& a){
		r = a.r;
		c = a.c;
		return *this;
	}
}rc;

typedef struct M
{
	char A[11][11];
	rc red,blue,goal;
	int R,C;
	M(){}
	M& rotate(M& copy){
		M *ret = new M;
		ret->R = copy.C;
		ret->C = copy.R;
		for(auto r = 0; r < ret->R; ++r){
			for(auto c = 0; c < ret->C; ++c){
				ret->A[r][c] = copy.A[c][ret->R-r-1];
			}
		}
		ret->red.r = copy.C-copy.red.c-1;ret->red.c = copy.red.r;
		ret->blue.r = copy.C-copy.blue.c-1;ret->blue.c = copy.blue.r;
		ret->goal.r = copy.C-copy.goal.c-1;ret->goal.c = copy.goal.r;
		return *ret;
	}
	bool set_input(){
		int num = goal.r;num*=10;
		num += goal.c;num*=10;
		num += red.r;num*=10;
		num += red.c;num*=10;
		num += blue.r; num*=10;
		num += blue.c;
		if(global.count(num))return false;
		global.insert(num);return true;
	}
	void view_M(){
		for(auto r = 0; r < this->R; ++r){
			for(auto c = 0; c < this->C; ++c){
				cout<<A[r][c];
			}cout<<endl;
		}cout<<endl;
		cout<<"red.r << ' '<<red.c: "<<red.r << ' '<<red.c<<endl;
		cout<<"blue.r << ' '<<blue.c: "<<blue.r << ' '<<blue.c<<endl;
		cout<<"goal.r << ' '<<goal.c: "<<goal.r << ' '<<goal.c<<endl;
	}
}M;

int push_left(M &a){
	rc ored = a.red,oblue = a.blue;
	int &i = ored.c,&j = oblue.c;
	if(ored.r == oblue.r && oblue.c < ored.c){
		while(a.A[oblue.r][j] != '#'){j--;if(a.A[oblue.r][j]=='O'){return -1;}}
		j++;
		swap(a.A[oblue.r][j],a.A[a.blue.r][a.blue.c]);
		while(a.A[ored.r][i] != '#'&&a.A[ored.r][i] != 'B'){i--;if(a.A[ored.r][i]=='O'){return 1;}}
		i++;
		swap(a.A[ored.r][i],a.A[a.red.r][a.red.c]);
	}else{
		bool endgame = false;
		while(a.A[ored.r][i] != '#'){i--;if(a.A[ored.r][i]=='O'){endgame = true;break;}}
		if(endgame)a.A[ored.r][a.red.c] = '.';
		else {
			i++;swap(a.A[ored.r][i],a.A[a.red.r][a.red.c]);
		}
		while(a.A[oblue.r][j] != '#' && a.A[oblue.r][j] != 'R'){j--;if(a.A[oblue.r][j]=='O'){return -1;}}
		if(endgame)return 1;
		j++;
		swap(a.A[oblue.r][j],a.A[a.blue.r][a.blue.c]);
	}
	a.blue = oblue;
	a.red = ored;
	return 0;
}
M rot[4];

int solve(M& a){
	queue<M>q;
	q.push(a);
	int ret = 0;
	while(!q.empty()){
		int sz = q.size();
		ret++;
		for(int i = 0 ; i < sz; i++ ){
			rot[0]= move(q.front());
			q.pop();
			if(!rot[0].set_input())continue;
			int pl;
			for(int j = 1; j <= 3; j++){
				rot[j] = move(rot[j-1].rotate(rot[j-1]));
			}
			for(int j = 0; j < 4; j++){
				pl = push_left(rot[j]);
				if(pl == 0){
					q.push(move(rot[j]));
				}else if(pl == 1){
					return ret;
				}
			}
		}
		if(ret == 10)break;
	}
	return -1; 
}

int main() {
	io
	int R,C;
	cin>>R>>C;
	M a;
	a.R = R;a.C = C;
	string tmp;
	for(auto r = 0; r < R; ++r){
		cin>>tmp;
		for(auto c = 0; c < C; ++c){
			a.A[r][c] = tmp[c];
			if(tmp[c] == 'B'){
				a.blue = {r,c};
			}else if(tmp[c] == 'R'){
				a.red = {r,c};
			}else if(tmp[c] == 'O'){
				a.goal = {r,c};
			}
		}
	}
	int ret = solve(a);
	cout<<ret<<endl;
	return 0;
}