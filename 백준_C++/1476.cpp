#include <iostream>
using namespace std;

int main(){
    int n1=0,n2=0,n3=0;
    int day=1;
    cin>>n1>>n2>>n3;
    while (1)
    {   
        if((n1==1) && (n2==1) && (n3==1))
            break;
        else{
            if(n1==1)n1=15;
            else n1-=1;
            if(n2==1)n2=28;
            else n2-=1;
            if(n3==1)n3=19;
            else n3-=1;
            day+=1;
        }
    }
    cout<<day;
}