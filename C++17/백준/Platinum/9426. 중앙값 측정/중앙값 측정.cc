#include<iostream>
using namespace std;
typedef long long ll;
const int MX=65535;
ll n,k,t[4*MX],d[4*MX];
void update(int node,int l,int r,int x,int cnt){
    if(r<x||x<l) return;
    if(l==r){
          t[node]+=cnt;
          return;
    }
    int mid=(l+r)/2;
    update(2*node,l,mid,x,cnt);
    update(2*node+1,mid+1,r,x,cnt);
    t[node]=t[2*node]+t[2*node+1];
}
int query(int node,int l,int r,int x){
    if(l==r) return l;
    int mid=(l+r)/2;
    if(t[2*node]>=x) return query(2*node,l,mid,x);
    else return query(2*node+1,mid+1,r,x-t[2*node]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>d[i];
        update(1,0,MX,d[i],1);
        if(i>=k){
            sum+=query(1,0,MX,(k+1)/2);
            update(1,0,MX,d[i-k+1],-1);
        }
    }
    cout<<sum;
}