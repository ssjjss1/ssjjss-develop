#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,ans;
vector<pair<int,int>> d;
long long t[2000004];
void update(int x, int node, int l, int r){
      if(l==r){
            t[node]=1;
            return;
      }
      int m=(l+r)/2;
      if(x<=m) update(x,node*2,l,m);
      else update(x,node*2+1,m+1,r);
      t[node]=t[node*2]+t[node*2+1];
}
int query(int x, int y, int node, int l, int r){
      if(x>r||y<l) return 0;
      if(x<=l&&r<=y) return t[node];
      int m=(l+r)/2;
      return query(x,y,node*2,l,m)+query(x,y,node*2+1,m+1,r);
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1,x;i<=n;i++) cin>>x,d.push_back({x,i});
      sort(d.begin(),d.end());
      for(auto i:d){
            ans+=query(i.second+1,n,1,1,n);
            update(i.second,1,1,n);
      }
      cout<<ans;
}