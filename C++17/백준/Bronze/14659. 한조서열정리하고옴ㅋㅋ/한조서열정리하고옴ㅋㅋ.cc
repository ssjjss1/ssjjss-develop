#include<iostream>
using namespace std;
int n,mx=0;
int d[30004];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  int h=0,cnt=0;
  for(int i=1,x;i<=n;i++){
    cin>>x;
    if(x>=h) mx=max(mx,cnt),cnt=0,h=x;
    else cnt+=1;
    if(i==n) mx=max(mx,cnt);
  }
  cout<<mx;
}