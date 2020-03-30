#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

array<pair<int,char>, 26> arr;

using pic =pair<int,char>;
// 91 Z
int main() {
	string go;
	cin>>go;
	int cnt = 0;
	for(char a = 'A';a <= 'Z';a++){
		arr[cnt++].second = a;
	}
	for(auto ch : go){
		if(ch >= 'a'){
			arr[ch-'a'].first++;	
		}else{
			arr[ch-'A'].first++;
		}
	}
	sort(arr.begin(),arr.end(),[](pic &a,pic &b){return a.first>b.first;});
	if(go.length()==1){
		cout<<arr[0].second;
	}else if(arr[0].first > arr[1].first){
		cout<<arr[0].second<<endl;
	}else {
		cout<<"?\n";
	}
	return 0;
}
