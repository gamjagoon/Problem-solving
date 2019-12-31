#include <iostream>
#include <list>
using namespace std;

#define TRUE 1
#define FALSE 0


int main(){
    int a,b,i=2;
    int r_1=1,r_2=1;
    int big;
    cin>>a>>b;
    if(a>b)big = a;
    else big = b;
    int buf[big]={0};
    //a와 b의 공통 약수를 다 구했다
    while(i<big){
        while(a%i==0 and b%i==0){
            a/=i;
            b/=i;
            buf[i]+=1;
        }
        i++;
    }
    for(int j=1;j<big;j++){
        if(buf[j]!=0){
            r_1*=(buf[j]*(j));
        }
    }
    r_2 = r_1*a*b;
    cout<<r_1<<'\n'<<r_2;
}