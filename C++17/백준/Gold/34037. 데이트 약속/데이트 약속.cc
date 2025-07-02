#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n>>m;
      
      vector<pair<long long, long long>> v(m+4);
      vector<long long> dp(m+4,0);
      
      v[0]={0,0};
      for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            v[i]={x,y};
      }
      
      if(v[m].first<n) v[++m]={n,0};
      
      for(int i=1;i<=m;i++) v[i].second+=v[i-1].second;

      for(int i=1;i<=m;i++){
            long long mx=-1e18;
            auto [x0, y0]=v[i-1];
            auto [x1, y1]=v[i];
            
            for(int j=0;j<i;j++){
                  auto [x2, y2]=v[j];
                  long long diff=x1-x2;
                  long long val1=diff*(diff+1)/2;
                  long long val2=(diff-1)*diff/2;
                  
                  long long c1=dp[j]+val1-(y1-y2);
                  long long c2=dp[j]+val2-(y0-y2);
                  mx=max({mx,c1,c2});
            }
            
            dp[i]=mx;
      }
      
      cout<<dp[m];
}