#include<bits/stdc++.h>
using namespace std;
int n;

string s="SciComLove";

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      string sc;
      cin>>sc;
      
      int cnt=0;
      for(int i=0;i<sc.length();i++){
            if(s[i]!=sc[i]) cnt+=1; 
      }
      
      cout<<cnt;
}