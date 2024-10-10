#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=1e5;
long long t[4*inf+4],d[inf+4];
int n,m;
int mul(int x){return (x>0)-(x<0);}
void init(int node,int l,int r){ 
    if(l==r){
        t[node]=mul(d[l]);
        return;
    }
    int m=(l+r)/2;
    init(node*2,l,m);
    init(node*2+1,m+1,r);
    t[node]=t[node*2]*t[node*2+1];
}
void update(int x,int v,int node,int l,int r){
    if(l==r){
        t[node]=mul(v);
        return;
    }
    int m=(l+r)/2;
    if(x<=m) update(x,v,node*2,l,m);
    else update(x,v,node*2+1,m+1,r);
    t[node]=t[node*2]*t[node*2+1];
}
long long query(int x,int y,int node,int l,int r){
    if(x>r||y<l) return 1;
    if(x<=l&&r<=y) return t[node];
    int m=(l+r)/2;
    return query(x,y,node*2,l,m)*query(x,y,node*2+1,m+1,r);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m){
        fill(t,t+4*inf+4,0);
        fill(d,d+inf+4,0);
        for(int i=1;i<=n;i++) cin>>d[i];
        init(1,1,n);
        for(int i=1,x,y;i<=m;i++){
            char c;
            cin>>c>>x>>y;
            if(c=='C') {
                update(x,y,1,1,n);
            }
            else {
                int ans=query(x,y,1,1,n);
                if(ans>0) cout<<"+";
                else if(ans==0) cout<<"0";
                else cout<<"-";
            }
        }
        cout<<"\n";
    }
}