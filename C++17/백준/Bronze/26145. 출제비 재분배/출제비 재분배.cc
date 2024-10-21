#include<iostream>
using namespace std;
int n,m;
long long a[2004];
int main(){
      cin>>n>>m;
      for(int i=1;i<=n;i++) cin>>a[i];
      for(int i=1;i<=n;i++){
            for(long long j=1,x;j<=(n+m);j++){
                  cin>>x;
                  a[i]-=x,a[j]+=x;
            }
      }
      for(int i=1;i<=(n+m);i++) cout<<a[i]<<" ";
}