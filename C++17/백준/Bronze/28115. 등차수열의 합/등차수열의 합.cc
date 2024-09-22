#include<iostream>
using namespace std;
int n;
long long a[101010],b[101010],c[101010]; 
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++) cin>>a[i];
      long long diff=a[2]-a[1];
      for(int i=1;i<n;i++) {
            if(a[i+1]-a[i]!=diff){
                  cout<<"NO";
                  return 0;
            }
      }
      for(int i=1;i<=n;i++) b[i]=a[i]+1,c[i]=-1;
      cout<<"YES\n";
      for(int i=1;i<=n;i++) cout<<b[i]<<" ";
      cout<<"\n";
      for(int i=1;i<=n;i++) cout<<c[i]<<" ";
}