#include <iostream>
#include <deque>
using namespace std;


int t,n;
string a,tmp;

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		deque<int>dq;
		cin>>a>>n>>tmp;
		bool l_to_r = true;
		bool er = false;
		int i = 1,res = 0,ch;
		while(n > 0){
			res = 0;
			while((ch = tmp[i++]) != ',' && ch != ']'){
				res *= 10;
				res += ch-'0';
			}
			dq.push_back(res);
			n--;
		}
		for(auto ele : a){
			if(ele == 'R'){
				l_to_r = l_to_r ? false : true;
			}
			else{
				if(dq.empty()){
					cout<<"error\n";
					er = true;
					break;
				}
				else if(l_to_r){
					dq.pop_front();
				}
				else{
					dq.pop_back();
				}
			}
		}
		if(!er){
			if(l_to_r){
				cout<<'[';
				while(dq.size() > 1){
					cout<<dq.front()<<',';
					dq.pop_front();
				}
				if(dq.size() == 1){
					cout<<dq.front();
					dq.pop_front();
				}
				cout<<"]\n";
			}
			else{
				cout<<'[';
				while(dq.size() > 1){
					cout<<dq.back()<<',';
					dq.pop_back();
				}
				if(dq.size() == 1){
					cout<<dq.front();
					dq.pop_front();
				}
				cout<<"]\n";
			}
		}
	}
}