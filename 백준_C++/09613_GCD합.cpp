#include <iostream>

#define MAX 1000
using namespace std;
int prime[MAX];
int count=2;
void Initialize_buf(int arr[]){
    for(int i = 0;i<MAX+1;i++){
        arr[i] = i;
    }
}

void prime_numbers(int arr[]){
    Initialize_buf(arr);
    arr[1]=0;
    int i=2;
    while(i<=MAX){
        for(int j=2;j<i;j++)
        {
            if(i%j==0){
                arr[i]=0;
                count++;
                break;
            }
        }
        i++;
    }
}
int main(){
    prime_numbers(prime);
    int only_prime[MAX+1-count]={};
    int l =0,sum=0;
    for (int i = 0; i < MAX; i++)
    {
        if(prime[i]!=0){
            only_prime[l]=prime[i];
            l++;
        }
    }
    
    int N;
    N = 10;
    // cin>>N;
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        for(int i=0;i<l;i++){
            if (only_prime[i]==n)
            {
                sum++;
            }
        }
    }
    printf("%d",sum);
    return 0;
}
