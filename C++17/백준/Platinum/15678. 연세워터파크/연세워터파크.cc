#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e5+4;
ll n,m,ans=-1e18;
ll t[INF*4],d[INF];
ll query(int node, int l, int r, int x, int y){
      if(y<l||r<x) return -1e18;
      if(x<=l&&r<=y) return t[node];
      int middle=(l+r)/2;
      return max(query(node*2,l,middle,x,y), query(node*2+1,middle+1,r,x,y));
}
void update(int node, int l, int r, int idx, ll x){
      if(r<idx||idx<l) return;
      if(l==r){
            t[node]=x;
            return;
      }
      int middle=(l+r)/2;
      update(node*2,l,middle,idx,x);
      update(node*2+1,middle+1,r,idx,x);
      t[node]=max(t[node*2],t[node*2+1]);
}
int main(){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>n>>m;
      for(int i=1;i<=n;i++) cin>>d[i];
      for(int i=1;i<=n;i++){
            int l=((i-m)<=0?1:i-m), r=i-1;
            ll x=query(1,1,n,l,r);
            if(x>0) d[i]+=x;
            update(1,1,n,i,d[i]);
            ans=max(ans, d[i]);
      }
      // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
      // cout<<"\n";
      cout<<ans;
}