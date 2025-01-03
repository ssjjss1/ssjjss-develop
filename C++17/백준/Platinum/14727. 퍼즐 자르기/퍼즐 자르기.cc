#include<bits/stdc++.h>
#define INF 100004
using namespace std;
long long n;
long long d[INF], t1[INF*4],t2[INF*4];

void update(int node, int l, int r){
      if(l==r){
            t1[node]=d[l];
            t2[node]=l;
            return;
      }
      int middle=(l+r)/2;
      update(node*2,l, middle), update(node*2+1,middle+1, r);
      if(t1[node*2]>t1[node*2+1]) t2[node]=t2[node*2+1];
      else t2[node]=t2[node*2];
      t1[node]=min(t1[node*2], t1[node*2+1]);
}

long long query(int node, int l, int r, int x, int y){
      if(y<l||x>r) return -1;
      if(x<=l&&r<=y) return t2[node];
      
      int middle=(l+r)/2;
      long long left=query(node*2, l, middle, x,y);
      long long right=query(node*2+1, middle+1, r, x,y);
      
      if(left==-1) return right;
      if(right==-1) return left;
      return d[left]<d[right]?left: right;
}

long long search(int l, int r){
      if(l>r) return -INF;
      long long idx=query(1,1,n,l,r);
      long long c_s=d[idx]*(r-l+1);
      
      long long l_s=search(l, idx-1), r_s=search(idx+1,r);
      
      return max({l_s, c_s, r_s});
}

int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++) cin>>d[i];
      update(1,1,n);
      
      long long mx=search(1,n);
      cout<<mx;
}