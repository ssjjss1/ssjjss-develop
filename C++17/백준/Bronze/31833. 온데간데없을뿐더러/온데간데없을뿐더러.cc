#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int n;
      cin>>n;
      for(int i=0;i<n;i++){
            string s;
            cin>>s;
            s1+=s;
      }
      
      for(int i=0;i<n;i++){
            string s;
            cin>>s;
            s2+=s;
      }
      
      if(stoll(s1)>stoll(s2)) cout<<s2;
      else cout<<s1;
}