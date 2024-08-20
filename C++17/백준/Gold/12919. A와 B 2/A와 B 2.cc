#include<iostream>
#include<algorithm>
using namespace std;
bool flag=0;
void f(string s, string t){
  if(s.size()==t.size()) {
    if(s==t) flag=1;
    return;
  }
  while(s.size()<t.size()){
   if(t[t.size()-1]=='A') {
     t.pop_back();
     f(s,t);
     t+='A';
   } 
   if(t[0]=='B'){
     reverse(t.begin(),t.end());
     t.pop_back();
     f(s,t);
   }
    return;
  }
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  string s1,s2;
  cin>>s1>>s2;
  f(s1,s2);
  if(flag) cout<<1;
  else cout<<0;
}