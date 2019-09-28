#include <iostream>
using namespace std;
int arr[8]={};
int arr_2[8]={};
int _sum(int n,int m){
    if(n>=m){
        return n-m;
    }
    else
    {
        return m-n;
    }
}
void _swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    int n;
    int result=0;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    //arr[n]에 값을 할당 했다
    int index=0;
    do{
        index = 0;
        for(int i = 0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                _swap(&arr[i],&arr[i+1]);
                index = i;
            }
        }
    }while(index!=0);//정렬 끝
    while (1)
    {
        int x1 = n-1,x2 = n-1;
        int value=0;
        while (x1>0 && arr[x1-1]>=arr[x1])
        {
            x1--;
        }
        if (x1 == 0)
        {
            break;
        }
        while (arr[x1-1]>=arr[x2])
        {
            x2--;
        }
        _swap(&arr[x1-1],&arr[x2]);
        x2 = n - 1;
        while (x1 < x2)
        {
            _swap(&arr[x1], &arr[x2]);
            x1++;
            x2--;
        }
        for(int i = 0;i<n-1;i++){
            value+=_sum(arr[i],arr[i+1]);
        }
        if(result<value){
            result = value;
        }
    }
    cout<<result;
    return 0;
}