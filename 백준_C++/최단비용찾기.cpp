#include <iostream>
using namespace std;
int arr[10][10]={};//전체 배열 10x10
int loc[1]={1};//순서의 마지막을 표시하는 수
int lowvalue[1]={10000000};//제일 작은 값
int _value[10]={};
/*배열에서의 교환*/
void _swap(int *a,int *b){
int temp = *a;
*a = *b;
*b = temp;
}
/*순열을 구한다 */
void _next(int n){
    int x1=n-1,x2=n-1;
    while (x1>0 && _value[x1-1]>_value[x1])
    {
        x1--;
    }

    if(x1==0){
        loc[0] = -1;
    }
    else
    {
        while (_value[x1-1]>=_value[x2])
        {
            x2--;
        }
        _swap(&_value[x2],&_value[x1-1]);
        x2 = n - 1;
        while (x1 < x2)
        {
            _swap(&_value[x1], &_value[x2]);
            x1++;
            x2--;
        }
    }
}
int main(){
    int n=0,h=0,w=0;
    cin>>n;
    for (h = 0; h < n; h++){
        for (w = 0; w < n; w++)
        {
            cin>>arr[h][w];
        }
    }

    for(int i = 0;i<n;i++){
        _value[i] = i+1;
        }
    while(loc[0]==1){
        _next(n);
        int memo = 0;
        for(int i = 0;i<n;i++){
            int now = _value[i]-1;
            int after;
            if(i+1==n)
                after = _value[0]-1;
            else
                after = _value[i+1]-1;
            if (arr[now][after]==0)
            {
                memo =10000000;
                break;
            }
            else
            {
                memo += arr[now][after];
            }
        }
        if (lowvalue[0] > memo)
        {
            lowvalue[0] = memo;
        }
    }
    cout<<lowvalue[0]<<endl;
    return 0;
}