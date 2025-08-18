#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    int m, t, k;
    cin >> n >> m >> t >> k;

    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }

    map<int, vector<tuple<int, int, int>>> mp;
    for(int i = 0; i < k; i++){
        int r, s, e, c;
        cin >> r >> s >> e >> c;
        mp[r].emplace_back(s, e, c);
    }

    map<int, int> mpc;
    if (m > 0) mpc[1] = a[0];
    for (int i = 1; i < m; i++) {
        if (a[i] != a[i - 1]) {
            mpc[i + 1] = a[i];
        }
    }
    
    mp[n + 1];

    vector<ll> ans(t + 4, 0);
    ll lrow = 1;

    for (auto &[r, vec] : mp) {
        ll nrow = (ll)r - lrow;
        if (nrow > 0) {
            auto it = mpc.begin();
            while (it != mpc.end()) {
                ll s = it->first;
                int C = it->second;
                auto nx = next(it);
                ll e = ((nx == mpc.end()) ? m : nx->first - 1);
                ll w = e - s + 1;
                if (w > 0) {
                    ans[C] += nrow * w;
                }
                it = nx;
            }
        }
        
        auto run = [&](int c) {
            auto it = mpc.find(c);
            if (it == mpc.end()) {
                auto prev = --mpc.upper_bound(c);
                mpc[c] = prev->second;
            }
        };

        for (auto &[s, e, c] : vec) {
            run(s); run(e + 1);
            
            auto is = mpc.find(s);
            auto ie = mpc.find(e + 1);
            
            mpc.erase(is, ie);
            mpc[s] = c;
        }

        lrow = r;
    }

    for (int i = 1; i <= t; i++) {
        cout << ans[i] << " ";
    }
}