#include<bits/stdc++.h>
using namespace std;
stack<char> stk;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      string s; cin>>s;
      for(auto c:s){
            if(c=='(') stk.push(c);
            else {
                  if(!stk.empty()&&stk.top()=='(') stk.pop();
                  else stk.push(c);
            }
      }
      cout<<stk.size();
}