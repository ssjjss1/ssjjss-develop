#include<iostream>
#include<stack>
using namespace std;
int n;
stack<int> stk; 
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  while(n--){
    string s;
    int m;
    cin>>s;
    if(s=="push"){
      cin>>m;
      stk.push(m);
    }
    else if(s=="top"){
      if(stk.empty()) cout<<-1<<"\n";
      else cout<<stk.top()<<"\n";
    }
    else if(s=="size"){
      cout<<stk.size()<<"\n";
    }
    else if(s=="pop"){
      if(stk.empty()) cout<<-1<<"\n";
      else cout<<stk.top()<<"\n",stk.pop();
    }
    else if(s=="empty"){
      if(stk.empty()){
        cout<<1<<"\n";
      }
      else cout<<0<<"\n";
    }
  }
}