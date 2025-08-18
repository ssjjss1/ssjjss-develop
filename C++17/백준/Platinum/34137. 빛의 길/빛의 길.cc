#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using T = tuple<ll,ll,ll,ll>;
const int INF = 200004;

vector<ll> tree(INF*4);
vector<ll> lazy(INF*4);
ll n;

void propagate(int node, int l, int r) {
    if (lazy[node] != 0) {
        tree[node] = lazy[node] * (r - l + 1);
        if (l != r) {
            lazy[node * 2] = lazy[node];      
            lazy[node * 2 + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node,int l,int r,int x,int y,ll val){
    propagate(node,l,r); 
    if(x>r || l>y) return;
    if(x<=l && r<=y){
        tree[node] = val * (r - l + 1);
        lazy[node] = val;
        return;
    }
    
    int middle=(l+r)/2;
    update(node*2,l,middle,x,y,val);
    update(node*2+1,middle+1,r,x,y,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int node,int l,int r,int x,int y){
    propagate(node,l,r); 
    if(x>r||l>y) return 0;
    if(x<=l && r<=y) return tree[node];
    
    int middle=(l+r)/2;
    return query(node*2,l,middle,x,y)+query(node*2+1,middle+1,r,x,y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll m,t,k;
    cin>>n>>m>>t>>k;
    vector<ll> a(m+4);
    for(int i=1;i<=m;i++) {
        cin>>a[i];
    }

    vector<T> qu(k);
    for(int i=0;i<k;i++){
        ll r,s,e,c;
        cin>>r>>s>>e>>c;
        qu[i]={r,s,e,c};
    }

    sort(qu.begin(),qu.end(),greater<T>());
    vector<ll> cnt(t+4,0);

    for(auto &[r,s,e,c]:qu){
        ll h=n-r+1;
        ll res=query(1,1,INF,s,e);
        cnt[c]+=h*(e-s+1)-res;
        update(1,1,INF,s,e,h);
    }

    for(int i=1;i<=m;i++){
        ll res=query(1,1,INF,i,i);
        cnt[a[i]]+=n-res;
    }

    for(int i=1;i<=t;i++) {
        cout<<cnt[i]<<" ";
    }
}