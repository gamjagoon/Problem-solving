#include <iostream>
using namespace std;

char str[15];
int n = 0;
int l = 0;
int *n_ptr = &n;
int *l_ptr = &l;
template <typename T>

void _swap(T *a,T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}
void _sort(char arr[]){
    int index;
    do
    {   index = 0;
        for(int i = 0;i < l-1;i++){
            if(arr[i]>arr[i+1]){
                _swap(&arr[i],&arr[i+1]);
                index = i;
            }
        }
    } while (index != 0);
}
void _reverse(int start, int end){
    end--;
    while(start<end){
        _swap(&str[start++],&str[end--]);
    }
}
void Input(){

    cin>>*n_ptr>>*l_ptr;
    for (int i = 0; i < l; i++)
    {
        cin>>str[i];
    }
    _sort(str);
}
// bool _increase(){
//     for(int i = 0;i<n-1;i++){
//         if(str[i]>str[i+1]){
//             return false;
//         }
//     }
//     return true;
// }
void Print(){
    for(int i = 0;i < n;i++){
        cout<<str[i];
    }
    cout<<'\n';
}


int main(){
    Input();
    return 0;
}