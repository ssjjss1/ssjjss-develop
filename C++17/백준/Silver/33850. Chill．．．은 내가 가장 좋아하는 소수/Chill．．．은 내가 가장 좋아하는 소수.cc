#include<bits/stdc++.h>
#define INF 100004
using namespace std;

long long d[4][INF*2], dp[INF*2];
bool visited[INF*2];

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      for(int i=2;i<=INF*2;i++){
          if(!visited[i]){
                for(int j=2*i;j<=INF*2;j+=i){
                      visited[j]=1;
                }
          }  
      }
      
      int n,a,b;
      cin>>n>>a>>b;
      
      for(int i=1;i<=2;i++){
            for(int j=1;j<=n;j++){
                  cin>>d[i][j];
            }
      }
      
      for(int i=1;i<=n;i++){
            long long r=d[1][i]+d[2][i];
            long long c1=d[1][i]+d[1][i+1];
            long long c2=d[2][i]+d[2][i+1];
            
            dp[i+1]=max(dp[i+1], dp[i]+(visited[r]?b:a));
            dp[i+2]=max(dp[i+2], dp[i]+(visited[c1]?b:a)+(visited[c2]?b:a));
      }
      
      cout<<dp[n+1];
}