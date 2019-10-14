#include <iostream>
#include <cstdio>

using namespace std;

int test_case;
int ptr;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>test_case;
	while(test_case--)
	{
		int arr_size,len,input_size;
		cin>>arr_size>>len>>input_size;
		uint8_t arr[arr_size+1];
		char progrem[len+1];
		fread(progrem,sizeof(char),len+1,stdin);
		progrem[len] = '\0';
		fread(arr,sizeof(uint8_t),input_size+1,stdin);
		arr[input_size] = '\0';
		cout<<progrem<<endl;
		cout<<arr<<endl;
	}
}