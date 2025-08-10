#include<bits/stdc++.h>
using namespace std;
map<int, long long> ma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ma[x]+=1;
    }

    long long ans=n*(n+1)/2-(n-1);
    for(auto [_, v]:ma){
        ans-=v*(v-1)/2;
    }

    cout<<ans;
}