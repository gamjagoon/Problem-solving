#include <iostream>
#include <stdio.h>
/*1 2 3 4 5    1 2 3 5 4    1 2 4 3 5   1 2 4 5 3   1 2 5 3 4   1 2 5 4 3
  1 3 2 4 5    1 3 2 5 4    1 3 4 2 5   1 3 4 5 2   1 3 5 2 4   1 3 5 4*/
using namespace std;
    int arr[8]={0};
void _swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i = 0;i < n;i++){
        arr[i] = i+1;
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<' ';
    }
        cout<<'\n';
    while (1)
    {
        int x1 = n-1,x2 = n -1;

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
        for(int i = 0;i<n;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}