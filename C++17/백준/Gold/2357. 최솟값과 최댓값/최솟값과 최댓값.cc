#include<iostream>
using namespace std;
int n, m;
int d[100004];
long long t1[400004], t2[400004];
void init(int node, int l, int r){
      if(l==r){
            t1[node]=d[l];
            t2[node]=d[l];
            return;
      }
      int m=(l+r)/2;
      init(node*2,l,m);
      init(node*2+1,m+1,r);
      t1[node]=min(t1[node*2+1], t1[node*2]);
      t2[node]=max(t2[node*2+1], t2[node*2]);
}
long long query1(int x, int y, int node, int l, int r){
      if(y<l||r<x) return 1e18+4;
      if(x<=l&&r<=y) return t1[node];
      int m=(l+r)/2;
      return min(query1(x,y,node*2,l, m), query1(x,y,node*2+1,m+1, r));
}
long long query2(int x, int y, int node, int l, int r){
      if(y<l||r<x) return -1e18+4;
      if(x<=l&&r<=y) return t2[node];
      int m=(l+r)/2;
      return max(query2(x,y,node*2,l, m), query2(x,y,node*2+1,m+1, r));
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      for(int i=1;i<=n;i++) cin>>d[i];
      init(1,1,n);
      while(m--){
            int x,y;
            cin>>x>>y;
            cout<<query1(x,y,1,1,n)<<" "<<query2(x,y,1,1,n)<<"\n";
      }
}