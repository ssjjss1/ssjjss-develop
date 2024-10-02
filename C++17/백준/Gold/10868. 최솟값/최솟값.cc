#include<iostream>
using namespace std;
int n,m;
int d[100004];
long long int t[400004];
void init(int node, int l, int r){
      if(l==r){
            t[node]=d[l];
            return;
      }
      int m=(l+r)/2;
      init(node*2, l, m); init(node*2+1, m+1, r);
      t[node]=min(t[node*2+1], t[node*2]);
}
long long query(int x, int y, int node, int l, int r){
      if(y<l||r<x) return 1e18+4;
      if(x<=l&&r<=y) return t[node];
      int m=(l+r)/2;
      return min(query(x,y,node*2, l, m), query(x,y,node*2+1, m+1,r));
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      for(int i=1;i<=n;i++) cin>>d[i];
      init(1,1,n);
      while(m--){
            int x,y;
            cin>>x>>y;
            cout<<query(x,y,1,1,n)<<"\n";
      }
}