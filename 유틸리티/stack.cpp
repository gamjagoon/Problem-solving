#include <iostream>
using namespace std;

class md{
private:
	int arr[200002];
	int f,b,sz;
public:
	md(){
		f=100001;
		b=100001;
		sz=0;
	}
	void push_front(int x){
		arr[f] = x;
		f--;sz++;
	}
	void push_back(int x){
		b++;sz++;
		arr[b] = x;
	}
	void pop_front(){
		if(sz == 0)cout<<"-1\n";
		else{
			cout<<arr[f+1]<<'\n';
			f++;sz--;
		}
	}
	void pop_back(){
		if(sz == 0)cout<<"-1\n";
		else{
			cout<<arr[b]<<'\n';
			b--;sz--;
		}
	}
	void size(){
		cout<<sz<<'\n';
	}
	void empty(){
		if(sz == 0)cout<<"1\n";
		else{
			cout<<"0\n";
		}
	}
	void front(){
		if(sz == 0)cout<<"-1\n";
		else{
			cout<<arr[f+1]<<'\n';
		}
	}
	void back(){
		if(sz == 0)cout<<"-1\n";
		else{
			cout<<arr[b]<<'\n';
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	md d;
	string s;
	int x;
	while(n--)
	{
		cin>>s;
		if(s[0]=='p'){
			if(s[1] == 'o'){
				if(s[4] =='f')d.pop_front();
				else d.pop_back();
			}
			else{
				cin>>x;
				if(s[5] =='f')d.push_front(x);
				else d.push_back(x);
			}
		}
		else if(s[0] == 's')d.size();
		else if(s[0] == 'e')d.empty();
		else if(s[0] == 'f')d.front();
		else d.back();
	}
}