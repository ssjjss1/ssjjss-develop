#include<iostream>
using namespace std;
const int mod=1000000007;
int n,m,k;
long long d[1000004],t[4000004];
void init(int node, int l, int r){
      if(l==r){
            t[node]=d[l];
            return;
      }
      int m=(l+r)/2;
      init(node*2,l,m); init(node*2+1, m+1,r);
      t[node]=(t[node*2+1]*t[node*2])%mod;
}
void update(int x, int v, int node, int l, int r){
      if(l==r) {
            t[node]=v;
            return;
      }
      int m=(l+r)/2;
      if(x<=m) update(x,v,node*2,l,m);
      else update(x,v,node*2+1,m+1,r);
      t[node]=(t[node*2+1]*t[node*2])%mod;
}
long long query(int x, int y, int node,int l, int r){
      if(r<x||y<l) return 1;
      if(x<=l&&r<=y) return t[node];
      int m=(l+r)/2;
      return (query(x,y,node*2,l,m)*query(x,y,node*2+1, m+1,r))%mod;
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m>>k;
      m+=k;
      for(int i=1;i<=n;i++) cin>>d[i];
      init(1,1,n);
      while(m--){
            int x,y,z;
            cin>>x>>y>>z;
            if(x==1) update(y,z,1,1,n);
            else cout<<query(y,z,1,1,n)%mod<<"\n";
      }
}