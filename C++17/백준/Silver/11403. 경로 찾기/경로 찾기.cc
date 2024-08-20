#include<iostream>
using namespace std;
int n;
int d[104][104];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>d[i][j];
    }
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(d[i][k]&&d[k][j]) d[i][j]=1;
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cout<<d[i][j]<<" ";
    }
    cout<<"\n";
  }
}