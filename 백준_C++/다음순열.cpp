#include <iostream>

using namespace std;

void _swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int arr[10000];

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<-1;
        return 0;
    }

    //x1 과 x2를 구한다 배열은 0부터 이므로 -1
    int x1 = n-1,x2 = n -1;

    //v[idx - 1] < v[idx]를 만족하는 가장 큰 idx를 찾는다
    while (x1>0 && arr[x1-1]>arr[x1])
    {
        x1--;
    }
    cout<<"biggest x1 = "<<x1<<endl;
    if (x1 == 0)
    {
        cout << -1 << "\n";
        return 0;
    }
    while (arr[x1-1]>arr[x2])
    {
        cout<<arr[x1-1]<<" > "<<arr[x2]<<endl;
        x2--;
    }
    cout<<"biggest x2 = "<<x2<<endl;
    cout<<arr[x1-1]<<" sawp "<<arr[x2]<<endl;
    _swap(&arr[x1-1],&arr[x2]);
    x2 = n - 1;
    while (x1 < x2)
    {
        cout<<"swap "<<x1<<" with "<<x2<<endl;;
        _swap(&arr[x1], &arr[x2]);
        x1++;
        x2--;
    }
    for(int i = 0;i<n;i++){
    cout<<arr[i]<<' ';
    }
    return 0;
}