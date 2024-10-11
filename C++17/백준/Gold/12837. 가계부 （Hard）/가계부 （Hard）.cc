#include<iostream>
using namespace std;
const int inf=1e7+7;
long long n,m,t[4*inf];
void update(int x, long long v, int node, int l, int r){
      if(l==r){
            t[node]+=v;
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
            long long x,y,z;
            cin>>x>>y>>z;
            if(x==1) update(y,z,1,1,n);
            else cout<<query(y,z,1,1,n)<<"\n";
      }
}