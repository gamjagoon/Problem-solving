#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int t;
    int bit = 0;
    ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
    while (t--) {
        int tmp = 0, n;
    	string str("");
		cin>>str;
        if (str == "all") bit = (1 << 21) - 1;
        else cin>>n;
        if (str[0] == 'a') bit |= (1 << (n - 1));
        else if (str[0] == 'r') bit &= ~(tmp | 1 << (n - 1));
        else if (str[0] == 'c') (bit & (1 << (n - 1))) ? cout<<'1'<<'\n' : cout<<'0'<<'\n';
        else if (str[0] == 't') bit = bit ^ (1 << (n - 1));
        else if (str[0] == 'e') bit = 1 >> 21;
    }
    return 0;
}