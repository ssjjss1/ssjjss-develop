#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> dpl(n), dpr(n);

    dpl[0] = 1;
    for(int i = 1; i < n; i++){
        dpl[i] = min(dpl[i - 1] + 1, v[i]);
    }

    dpr[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--){
        dpr[i] = min(dpr[i + 1] + 1, v[i]);
    }

    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += min(dpl[i], dpr[i]);
    }

    cout << ans;
}