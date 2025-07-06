#include<bits/stdc++.h>
using namespace std;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      int t;
      cin>>t;
      while(t--){
            long long n,x;
            cin>>n>>x;
            
            vector<long long> p(x);
            for(int i=0;i<x;i++){
                  cin>>p[i];
            }
            
            vector<long long> l(x+4),r(x+4);
            l[0]=0;
            r[0]=p[0]-1;
            l[x]=p[x-1]+1;
            r[x]=n+14;
            for(int i=1;i<x;i++){
                  l[i]=p[i-1]+1;
                  r[i]=p[i]-1;
            }
            
            vector<long long> dp(x+4, -1);
            dp[0] = 0;

            for(int i=0; i<x; i++){
                  if(dp[i] == -1 || l[i] > r[i]) continue;

                  for(int j=i+1; j<=x; j++){
                        if(l[j] > r[j]) continue;
                        if(r[i] + 4 >= l[j]){
                              if(dp[i] + 4 <= l[j]) dp[j]=l[j];
                              else if(dp[i] + 4 <=  r[j]){
                                    if(dp[j]==-1) dp[j]=dp[i]+4;
                                    else dp[j]=min(dp[j], dp[i]+4);
                              }
                        }
                  }
            }
            
            // for(int i=0;i<=x;i++) cout<<dp[i]<<" ";
            // cout<<"\n";
            cout << (dp[x] != -1 ? "POSSIBLE\n" : "IMPOSSIBLE\n");
      }
}