#include <iostream>
#include <ctype.h>
using namespace std;

string ori,argu;


int main()
{
	cin>>ori;
	int len;
	while(1){
		cin>>argu;
		if(argu.back() == ';'){
			cout<<ori;
			argu.pop_back();
			len = argu.length();
			int i;
			for(i = len-1; i > 0;--i){
				if(isalpha(argu[i]))break;
				else if(argu[i] == ']'){
					cout<<"[]";
					i--;
				}
				else{
				cout<<argu[i];
				}
			}
			cout<<' ';
			for(int s = 0;s <= i;++s){
				cout<<argu[s];
			}
			cout<<";\n";
			break;
		}
		else {
			cout<<ori;
			argu.pop_back();
			len = argu.length();
			int i;
			for(i = len-1; i > 0;--i){
				if(isalpha(argu[i]))break;
				else if(argu[i] == ']'){
					cout<<"[]";
					i--;
				}
				else{
				cout<<argu[i];
				}
			}
			cout<<' ';
			for(int s = 0;s <= i;++s){
				cout<<argu[s];
			}
			cout<<";\n";
		}
	}
}