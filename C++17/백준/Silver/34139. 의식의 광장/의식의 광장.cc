#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h,n;
    cin >> h >> n;
    
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        a[i]={v, i};
    }

    sort(a.begin(), a.end());

    vector<int> ans(n+4);
    int cx=1;
    for(auto [v, idx]:a){
        ans[idx]=cx++;
    }

    cout<<"YES\n";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}