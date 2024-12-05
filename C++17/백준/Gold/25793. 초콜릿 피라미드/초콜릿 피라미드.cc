#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>t;
      while(t--){
            long long n,m; cin>>n>>m;
            if(n>m) swap(n,m);
            long long p=m-n;
            long long ans1=0, ans2=0;
            ans1=n*(n+1)*(2*n+1)/3 - n*(n+1) + p*n*(n+1) - n*p;
            ans2+=(ans1+n);
            cout<<ans2<<" "<<ans1<<"\n";
      }
}