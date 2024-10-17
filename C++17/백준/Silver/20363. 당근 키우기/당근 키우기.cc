#include<iostream>
using namespace std;
long long n,m;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      if(n>m) cout<<n+m/10+m;
      else cout<<m+n/10+n;
}