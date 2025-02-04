#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,int> ma;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n>>m;
      
      for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            ma[s]=1;
      }
      
      int cnt=0;
      for(int i=1;i<=m;i++){
            string s;
            cin>>s;
            if(ma[s]) cnt+=1;
      }
      
      cout<<cnt;
}