#include<iostream>
#include<stack>
using namespace std;
int n;
stack<char> stk; 
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  while(n--){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
      if(!stk.empty()){
        if(stk.top()=='('&&s[i]==')') stk.pop();
        else stk.push(s[i]);
      }
      else stk.push(s[i]);
    }
    if(stk.empty()) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    while(stk.size()) stk.pop();
  }
}