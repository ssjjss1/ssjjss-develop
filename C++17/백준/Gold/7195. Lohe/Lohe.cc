#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, k;
    cin >> n >> k;

    vector<long long> d(n+1, 0), sum(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
        sum[i] = sum[i-1] + d[i];
    }

    if(n <= 2 * k) {
        cout << sum[n];
        return 0;
    }

    vector<long long> v(n - k + 2);
    for(int i = 1; i <= n - k + 1; i++) {
        v[i] = sum[i + k - 1] - sum[i - 1];
    }

    vector<long long> r(n - k + 4, 0);
    for(int i = n - k + 1; i >= 1; i--) {
        r[i] = max(v[i], r[i+1]);
    }

    long long ans = 0;
    for(int i = 1; i <= n - 2 * k + 1; i++) {
        ans = max(ans, v[i] + r[i + k]);
    }

    cout << ans;
}