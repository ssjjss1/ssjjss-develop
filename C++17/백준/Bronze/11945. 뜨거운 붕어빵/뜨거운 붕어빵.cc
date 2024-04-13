#include<iostream>
using namespace std;
int n,m;
char a[11][11];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=m;j>=1;j--){
      cout<<a[i][j];
    }
    cout<<"\n";
  }
}