#include<bits/stdc++.h>
using namespace std;
int n,m,len;
vector<string> v;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n>>m;
      for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            v.push_back(s);
            len+=s.size();
      }
      
      m-=len;
      int base=m/(n-1);
      int ep=m-base*(n-1);
      for(int i=1;i<n;i++){
            if(ep>0&&v[i][0]>='a'&&v[i][0]<='z') v[i]="_"+v[i], ep-=1;
      }
      for(int i=n-1;i>=1;i--){
            if(ep>0&&v[i][0]>='A'&&v[i][0]<='Z') v[i]="_"+v[i], ep-=1;
      }
      
      for(int i=1;i<n;i++){
            for(int j=0;j<base;j++){
                  v[i]="_"+v[i];
            }
      }
      for(auto i:v) cout<<i;
}