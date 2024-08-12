#include<iostream>
using namespace std;
int n,m,x,y;
int d[1004][1004];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m>>x>>y;
  for(int i=1;i<=n+x;i++){
    for(int j=1;j<=m+y;j++){
      cin>>d[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(i+x<=n&&j+y<=m){
        d[i+x][j+y]-=d[i][j];
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<d[i][j]<<" ";
    }
    cout<<"\n";
  }
}