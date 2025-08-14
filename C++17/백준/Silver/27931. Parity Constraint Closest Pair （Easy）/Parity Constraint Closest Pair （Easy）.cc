#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<long long> odd, even;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        if(x%2) odd.push_back(x);
        else even.push_back(x);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    long long mn1=INF, mn2=INF;
    if(odd.size()>1){
        for(int i=1;i<odd.size();i++){
            mn1 = min(mn1, odd[i] - odd[i-1]);
        }
    }
    if(even.size()>1){
        for(int i=1;i<even.size();i++){
            mn1 = min(mn1, even[i] - even[i-1]);
        }
    }
    if(even.size()>0&&odd.size()>0){
        int idx1=0, idx2=0;
        while(idx1<even.size() && idx2 < odd.size()){
            if(even[idx1] < odd[idx2]){
                mn2 = min(mn2, odd[idx2] - even[idx1]);
                idx1+=1;
            } else {
                mn2 = min(mn2, even[idx1] - odd[idx2]);
                idx2+=1;
            }
        }
    }

    cout<<(mn1==INF?-1:mn1)<<" "<<(mn2==INF?-1:mn2);
}