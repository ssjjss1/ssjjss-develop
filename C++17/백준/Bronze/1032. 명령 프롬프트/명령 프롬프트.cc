#include<iostream>
using namespace std;
string s,s1;
int n;
int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    if(i==1) cin>>s;
    else{
      cin>>s1;
      for(int j=0;j<s.length();j++){
        if(s1[j]!=s[j]) s[j]='?';
      }
    }
  }
  cout<<s;
}