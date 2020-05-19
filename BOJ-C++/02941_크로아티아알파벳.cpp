#include <iostream>

using namespace std;

string tmp;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>tmp;
  int res = 0;
  int sz = tmp.size();
  for(int c = 0;c < sz-1;){
    if(tmp[c]=='c'){
      if(tmp[c+1]=='=' || tmp[c+1] =='-'){
        res++;
        c+=2;
      }else {
        res++;
        c++;
      }
    }
    else if(c < sz-2 && tmp[c]=='d'&&tmp[c+1]=='z' &&tmp[c+2]=='='){
      res++;
      c+=3;
    }
    else if(tmp[c]=='d'&&tmp[c+1]=='-'){
      res++;
      c+=2;
    }else if(tmp[c] =='l' && tmp[c+1]=='j'){
      res++;
      c+=2;
    }else if(tmp[c]=='n' && tmp[c+1]=='j'){
      res++;
      c+=2;
    }else if(tmp[c]=='s' &&tmp[c+1] == '='){
      res++;
      c+=2;
    }else if(tmp[c]=='z' &&tmp[c+1]=='='){
      res++;
      c+=2;
    }else{
      res++;
      c++;
    }
  }
  if(tmp[sz-1] == '=' || tmp[sz-1] =='-'){
    cout<<res<<"\n";
  }else if(tmp[sz-1] =='j' &&(tmp[sz-2]=='n' || tmp[sz-2] =='l')){
    cout<<res<<"\n";
  }else {
    cout<<res+1<<"\n";
  }
}