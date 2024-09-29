#include<iostream>
#include<vector>
using namespace std;
int n,sum,x,y;
int d[104];
int dp[104][10004],a[104][10004];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++) cin>>d[i],sum+=d[i];
      if(sum%2) {
            cout<<-1;
            return 0;
      }
      dp[0][0]=1;
      for(int i=1;i<=n;i++){
            for(int j=0;j<=sum/2;j++) if(dp[i-1][j]) dp[i][j]=1;
            for(int j=d[i];j<=sum/2;j++) if(dp[i-1][j-d[i]]) dp[i][j]=1,a[i][j]=1;
      }
      if(sum%2||!dp[n][sum/2]){
            cout<<-1;
            return 0;
      } 
      vector<int> v1,v2;
      for(int i=n,j=sum/2;i>0;i--) {
            if(a[i][j]) v1.push_back(d[i]),j-=d[i];
            else v2.push_back(d[i]);
      }
      for(int i=1;i<=n;i++){
            if(x<=y) cout<<v1.back()<<" ",x+=v1.back(),v1.pop_back();
            else cout<<v2.back()<<" ", y+=v2.back(),v2.pop_back();
      }
}