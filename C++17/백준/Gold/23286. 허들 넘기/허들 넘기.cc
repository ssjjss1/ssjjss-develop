#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int inf=1e9+4;
int n,m,k;
int d[304][304];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      d[i][j]=inf;
    }
  }
  for(int i=1;i<=n;i++) d[i][i]=0;
  for(int i=1,x,y,z;i<=m;i++){
    cin>>x>>y>>z;
    d[x][y]=z;
  }
  for(int p=1;p<=n;p++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(d[i][j]>max(d[i][p],d[p][j])){
          d[i][j]=max(d[i][p],d[p][j]);
        }
      }
    }
  }
  for(int i=1,x,y;i<=k;i++){
    cin>>x>>y;
    if(d[x][y]==inf) cout<<-1<<"\n";
    else cout<<d[x][y]<<"\n";
  }
}