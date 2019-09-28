#include <iostream>

using namespace std;
int Arr[49]={};
bool Select[49]={};
int result[6]={};
//result에 n이 있으면 false
void Print(int MAX)
{
    for (int i = 0; i < MAX; i++)
    {
        if (Select[i] == true)
        {
            cout << Arr[i] <<' ';
        }
    }
    cout <<'\n';
}
void DFS(int Idx, int Cnt,int MAX)
{
    if (Cnt == 6)
    {
        Print(MAX);
        return;
    }
 
    for (int i = Idx; i < MAX; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;

        DFS(i, Cnt + 1,MAX);
        Select[i] = false;
    }
}
int main(){
    int n;
    while (1)
    {
        cin>>n;
        if(n == 0)break;
        fill_n(Arr,49,0);
        for (int i = 0; i < n; i++)
        {
            cin>>Arr[i];
        }
        DFS(0,0,n);
        cout<<'\n';
    }
    return 0;
}