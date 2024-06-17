#include<iostream>
using namespace std;
int a[]={1,2,5,7};
int b[100001];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  fill(b,b+100001,1e9);
  b[0]=0;
  for(int i=0;i<4;i++){
    for(int j=a[i];j<=100000;j++){
      b[j]=min(b[j],b[j-a[i]]+1);
    }
  }
  int n;
  cin>>n;
  cout<<b[n];
}