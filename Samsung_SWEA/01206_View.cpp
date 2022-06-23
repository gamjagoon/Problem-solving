#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int buffer[1000];
    for(int test_case = 1; test_case <= 10; ++test_case)
	{
		int cnt;
        cin>>cnt;
        for(int i = 0 ; i < cnt; i++){
        	cin>>buffer[i];
        }

        int result = 0;
        int l_2, l_1, r_1, r_2, n, min;
        for (int i = 2; i < cnt-2; i++)
        {
            n = buffer[i];
            min = 255;
            l_2 = n - buffer[i-2];
            min = l_2 < min ? l_2 : min;
            l_1 = n - buffer[i-1];
            min = l_1 < min ? l_1 : min;
            r_1 = n - buffer[i+1];
            min = r_1 < min ? r_1 : min;
            r_2 = n - buffer[i+2];
            min = r_2 < min ? r_2 : min;
            if(min < 0)min = 0;
            result += min;
        }
        cout << "#" << test_case << ' ' <<result <<'\n';
	}
	return 0;
}