#include<iostream>
#include<stack>
using namespace std;
int n,mx;
string s;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>s;
  stack<char> stk;
  for(int i=0;i<s.size();i++){
    if(s[i]=='('||s[i]=='['||s[i]=='{'){
      stk.push(s[i]);
      if(s[i]=='(') n+=1;
      else if(s[i]=='{') n+=2;
      else n+=3;
    }
    else if(s[i]==')'||s[i]==']'||s[i]=='}'){
      stk.pop();
      if(s[i]==')') n-=1;
      else if(s[i]=='}') n-=2;
      else n-=3;
    }
    else{
      mx=max(mx,n);
    }
  }
  cout<<mx;
}