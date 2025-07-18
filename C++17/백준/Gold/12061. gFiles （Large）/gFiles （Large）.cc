#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int test = 1; test <= t; test++) {
        int n;
        cin >> n;

        vector<pair<long long, long long>> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        long long l = 1, r = 1e15;
        for (auto [p, k] : v) {
            if (p == 100) {
                l = max(l, k);
                r = min(r, k);
            } else if (p == 0) {
                l = max(l, 100 * k + 1);
            } else {
                long long lo = (100 * k) / (p + 1) + 1;
                long long hi = (100 * k) / p;
                l = max(l, lo);
                r = min(r, hi);
            }
        }

        long long ans = -1;
        if (l <= r) {
            if (l == r) ans = l;
            else ans = -1; 
        }

        cout << "Case #" << test << ": " << ans << "\n";
    }
}