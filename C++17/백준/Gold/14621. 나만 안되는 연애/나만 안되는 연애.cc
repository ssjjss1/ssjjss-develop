#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int> d(1004,0);
int f(int x){if(x==d[x])return x;return d[x]=f(d[x]);}
void g(int x,int y){x=f(x),y=f(y);if(x!=y)d[x]=y;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    vector<char> a(n+4);
    vector<pair<int,pair<int,int>>> v;
    for(int i=1;i<=n;i++)d[i]=i;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,x,y,z;i<=m;i++)cin>>x>>y>>z,v.push_back({z,{x,y}});
    sort(v.begin(),v.end());
    int ans=0,cnt=0;
    for(auto i:v){
        int x=i.second.first,y=i.second.second,z=i.first;
        if(a[x]!=a[y]){
            if(f(x)!=f(y)){
                g(x,y);
                ans+=z;
                cnt+=1;
            }
            if(cnt==n-1) break;
        }
    }
    if(cnt==n-1)cout<<ans;
    else cout<<-1;
}