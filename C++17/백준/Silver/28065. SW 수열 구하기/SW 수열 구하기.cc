#include<iostream>
using namespace std;
int n;
int a[5004];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      int t=n/2+n%2;
      for(int i=1;i<=t;i++) a[2*(i-1)+1]=i;
      for(int i=0;i<n-t;i++) a[2*(i+1)]=n-i;
      for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}