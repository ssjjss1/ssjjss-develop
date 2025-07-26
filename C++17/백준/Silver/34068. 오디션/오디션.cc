#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<long long> a(n+4, 0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        a[u]+=1;
    }

    vector<long long> v; 
    for(int i=1;i<=n;i++){
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());

    long long prev=-1, ans=0;
    for(auto cnt:v){
        if(prev==-1) prev=cnt;
        else{
            if(prev>=cnt) {
                ans+=prev-cnt+1;
                prev+=1;
            } else{
                prev=cnt;
            }
        }
    }

    cout<<ans;
}