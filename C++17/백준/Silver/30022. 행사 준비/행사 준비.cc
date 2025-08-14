#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    vector<P> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second; 
    }

    sort(v.begin(), v.end(), [](const P &A, const P &B) {
        return abs(A.first - A.second) > abs(B.first - B.second);
    });

    ll ans = 0;
    int cntA = 0, cntB = 0;
    for (auto &[p, q] : v) {
        if ((p < q && cntA < a) || cntB >= b) {
            ans += p;
            cntA+=1;
        } else {
            ans += q;
            cntB+=1;
        }
    }

    cout << ans;
}