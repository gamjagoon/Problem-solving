#include <iostream>
using namespace std;
int h,m;
bool flag = false;

int main() {
    cin>>h>>m;
    m -= 45;
    if(m < 0){
        flag = true;
    }
    if(flag){
        if(h == 0){
            h = 23;
        }else {
            h-=1;
        }
        m += 60;
    }
    cout<<h<<' '<<m;
}