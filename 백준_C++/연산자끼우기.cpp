#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000000000
#define MIN -1000000000
void Input_box();
int _count[4];
int _count_2[4];
int num[11];
int high = MIN;
int low = MAX;
int *h_ptr = &high;
int *l_ptr = &low;
int box[10];
vector <int> b;
void _reverse(int start,int end){
    end--;
    while(start<end){
        swap(box[start++],box[end--]);
    }
}
void Input(){
    int n;
    cin >> n;
    for(int i = 0;i < n; i++){
        cin>>num[i];
    }
    for(int i = 0;i < 4; i++){
        cin>>_count[i];
        _count_2[i] = _count[i];
    }
}
void Print(){
    cout<<high<<'\n'<<low;
}
void Input_box(){
    for(int i = 0;i < 4; i++){
        
        while (_count[i]!=0)
        {
            _count[i]-=1;
            b.push_back(i+1);
        }
    }
}
bool next_permutation_my(int start,int end){
    if(start == end){
        // cout<<"false"<<'\n';
        return false;
    }
    if(start + 1 == end){
        // cout<<"false"<<'\n';
        return false;
    }
    int i = end -1;
    while(true){
        int j = i--;
        if(box[i]<box[j]){
            int k = end;
            while(!(box[i]<box[--k]));
            swap(box[i],box[k]);
            _reverse(j,end);
            return true;
        // cout<<"do"<<endl;
        }
        if(i == start){
            _reverse(start,end);
        // cout<<"false"<<'\n';
            return false;
        }
    }
}
void DFS(){
    Input_box();
    for(auto i = 0;i<b.size();i++){
        box[i] = b[i];
    }
    bool a=true;
    while (a == true)
    {
        int now = num[0];
        // cout<<"first now"<< now<<'\n';
        for(int i = 0;i<b.size();i++){
            if(box[i]==1){
                now +=num[i+1];
                // cout<<"+ result = "<<now<<endl;
            }
            if(box[i]==2){
                now -=num[i+1]; 
                // cout<<"- result = "<<now<<endl;
            }
            if(box[i]==3){
                now *= num[i+1]; 
                // cout<<"X result = "<<now<<endl;
            }
            if(box[i]==4){
                now /= num[i+1]; 
                // cout<<"/ result = "<<now<<endl;
            }
        }
        *h_ptr = max(*h_ptr,now);
        *l_ptr = min(*l_ptr,now);
        a = next_permutation_my(0,b.size());
    }
}
int main(){
    Input();
    // //벡터 디버깅용
    // Input_box();
    // cout<<'\n';
    // for(auto i = 0;i<b.size();i++){
    //     cout<<b[i]<<' ';
    // }
    // cout<<'\n';
    DFS();
    Print();
}
