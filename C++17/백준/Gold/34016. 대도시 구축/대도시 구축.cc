#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n>>m;
      
      map<long long,long long> ma;
      long long ans=n+n*(n+1)/2-2;
      vector<long long> node;
      for(int i=1;i<=m;i++){
            long long u,v;
            cin>>u>>v;
            ma[u]=v;
            ma[v]=u;
            
            if(u==1) node.push_back(v);
      }
      
      sort(node.begin(),node.end(), greater<>());
      
      for(long long u : node){
            for(long long i=2;;i++){
                  if(u==i||ma[i]==u) continue;
                  ans+=(i-1);
                  ma[u]=i;
                  ma[i]=u;
                  break;
            }
      }
      
      cout<<ans;
}