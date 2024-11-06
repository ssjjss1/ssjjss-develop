#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
vector<long long> v;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      for(long long i=1,x;i<=n;i++) cin>>x,v.push_back(x);
      sort(v.begin(),v.end());
      int l=0, r=v.size()-1;
      while(l<r){
            if(v[l]+v[r]<=m) cnt+=1, l+=1;
            r-=1;
      }
      cout<<cnt;
}