#include<iostream>
using namespace std;
int n,m;
long long t[4000004];
void update(int x,int v, int node, int l, int r){
      if(l==r){
            t[node]=v;
            return;
      }
      int m=(l+r)/2;
      if(x<=m) update(x,v,node*2,l,m);
      else update(x,v,node*2+1,m+1,r);
      t[node]=t[node*2]+t[node*2+1];
}
long long query(int x, int y, int node, int l, int r){
      if(x>r||y<l) return 0;
      if(x<=l&&r<=y) return t[node];
      int m=(l+r)/2;
      return query(x,y,node*2,l,m)+query(x,y,node*2+1,m+1,r);
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      while(m--){
            int x,y,z;
            cin>>x>>y>>z;
            if(x) update(y,z,1,1,n);
            else {
                  if(y>z) swap(y,z);
                  cout<<query(y,z,1,1,n)<<"\n"; 
            }
      }
}