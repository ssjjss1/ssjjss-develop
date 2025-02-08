#include<bits/stdc++.h>
using namespace std;
int n,m,k;

int A[104][104], B[104][104];

int main(){
      ios_base::sync_with_stdio(0);cin.tie(0);
      cin>>n>>m;
      for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  cin>>A[i][j];
            }
      }
      
      cin>>m>>k;
      for(int i=1;i<=m;i++){
            for(int j=1;j<=k;j++){
                  cin>>B[i][j];
            }
      }
      
      for(int i=1;i<=n;i++){
            for(int p=1;p<=k;p++){
                  int sum=0;
                  for(int j=1;j<=m;j++){
                        sum+=A[i][j]*B[j][p];
                  }
                  cout<<sum<<" ";
            }
            cout<<"\n";
      }
}