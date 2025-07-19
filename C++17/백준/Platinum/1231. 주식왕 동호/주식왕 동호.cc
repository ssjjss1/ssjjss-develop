#include<bits/stdc++.h>
using namespace std;

const int INF=500000;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      int C,D,M;
      cin>>C>>D>>M;
      vector<vector<int>> pro(C+4, vector<int>(D+4));
      for(int i=1;i<=C;i++){
            for(int j=1;j<=D;j++){
                  cin>>pro[i][j];
            }
      }
      
      vector<int> dp(INF+4,0);
      for(int d=2;d<=D;d++){
            fill(dp.begin(), dp.end(),0);
            
            for(int i=1;i<=C;i++){
                  int prev=pro[i][d-1];
                  int diff=pro[i][d]-prev;
                  
                  if(diff>0){
                        for(int j=prev;j<=M;j++){
                              dp[j]=max(dp[j], dp[j-prev]+diff);
                        }
                  }
            }
            
            M+=dp[M];
      }
      
      cout<<M;
}