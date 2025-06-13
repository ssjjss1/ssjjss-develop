#include<bits/stdc++.h>
using namespace std;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      int t;
      cin>>t;
      while(t--){
            string s;
            cin>>s;
            
            int len=s.size()/2-1;
            cout<<(s[len]==s[len+1]?"Do-it\n":"Do-it-Not\n");
      }
}