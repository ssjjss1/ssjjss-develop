#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int INF=1e9+7;
int n,m;
int dp[504][504];
vector<pair<int,int>> v;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1,x,y;i<=n;i++) cin>>x>>y, v.push_back({x,y});
      for(int len=2;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                  int j=i+len-1;
                  dp[i][j]=INF;
                  for(int k=i;k<j;k++){
                        int t=dp[i][k]+dp[k+1][j]+v[i].first*v[k].second*v[j].second;
                        dp[i][j]=min(dp[i][j], t);
                  }
            }
      }
      cout<<dp[0][n-1];
}