#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int test=1;test<=t;test++){
        int n; cin>>n;
        vector<int>v1(n), v2(n);
        for(int&i:v1)cin>>i;
        for(int&i:v2)cin>>i;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<>());
        long long ans=0;
        for(int i=0;i<n;i++)ans+=1LL*v1[i]*v2[i];
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
    return 0;
}