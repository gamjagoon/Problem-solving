#include<iostream>

using namespace std;

string str;
bool ch[50];

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int t = 0;cin>>t;
	cin>>str;
	t--;
	string tmp;
	while(t--){
		cin>>tmp;
		for(int i = 0; i < tmp.length();i++){
			if(str[i] != tmp[i]){
				ch[i] = true;
			}
		}
	}
	for(int i = 0 ; i < str.length();i++){
		if(!ch[i]){
			cout<<str[i];
		}else cout<<'?';
	}
}