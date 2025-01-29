#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    vector<int> a(n+4), water_sum(n+4,0), evap_sum(n+4,0);
    vector<int> cnt(n+4,0);
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        water_sum[i]=water_sum[i-1]+a[i];
    }
    
    int evap_cnt=0;
    
    for(int i=1;i<=n;i++){
        int idx = i + 1 + (a[i] / m);
        evap_sum[i]+=evap_sum[i-1];
        if(idx <= n) {
            cnt[idx] += 1;
            evap_sum[idx] += a[i] % m;
        }
        
        if(cnt[i]){
            evap_cnt -= cnt[i];
        }
        
        if(evap_cnt > 0){
            evap_sum[i] += m * evap_cnt;
        }
        evap_cnt+=1;
    }
    
    while(q--){
        int mode, x;
        cin>>mode>>x;
        if(mode==1){
            cout << water_sum[x] - evap_sum[x] << "\n";
        }else{
            cout<<evap_sum[x]-evap_sum[x-1]<<"\n";
        }
    }
}