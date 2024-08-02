#include<iostream>
using namespace std;
int n,m;
int d[1004][1004];
int max(int x, int y,int z){
  return max(x,max(y,z));
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>d[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      d[i][j]=max(d[i-1][j],d[i-1][j-1],d[i][j-1])+d[i][j];
    }
  }
  cout<<d[n][m];
}