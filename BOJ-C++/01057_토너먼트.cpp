/*
Date : 02/07/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/1057
summary : 
*/
#include <iostream>
using namespace std;

int main(void){
    int totalmember;
    int imm, kim;
    int count=0;
 
    cin>>totalmember>>imm>>kim;
 
    if (totalmember < kim || totalmember < imm){
        count = -1;
    }
    else{
        while (kim != imm){
            kim = (kim + 1) / 2;
            imm = (imm + 1) / 2;
            count++;
        }
    }
 
    cout<<count<<endl;
    return 0;
}