#include <bits/stdc++.h>
using namespace std;
long long n, m, t;
vector<pair<long long, long long>> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> t;
    for (int i = 1; i <= t; i++) {
        long long x, y;
        cin >> x >> y;
        if (n < x || m < y) continue;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    vector<long long> dp;
    for (auto [x, y] : v) {
        auto it = upper_bound(dp.begin(), dp.end(), y);
        if (it == dp.end()) dp.push_back(y);
        else *it = y;
    }

    cout << dp.size();
}