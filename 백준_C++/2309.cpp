#include <iostream>
using namespace std;
int main(){
    int man[9] = {0};
    int i;
    for(i =0;i<9;i++){
        cin>>man[i];
    }
    int total_man=0;
    for(i = 0;i<9;i++){
        total_man+=man[i];
    }
    for(i = 0;i<9;i++){
        for(int j = i+1;j<9;j++){
            int v=total_man;
            v -=(man[i]+man[j]);
            if(v == 100){
                man[i] = 0;
                man[j] = 0;
                int index;
                do
                {
                    index=0;
                    for(i=0;i<8;i++){
                        if(man[i]>man[i+1]){
                            int temp =man[i];
                            man[i] = man[i+1];
                            man[i+1] = temp;
                            index = i;
                        }
                    }
                } while (index!=0);
                for(i=2;i<9;i++)
                {
                    cout<<man[i]<<endl;
                }
                break;           
            }
        }
    }
}