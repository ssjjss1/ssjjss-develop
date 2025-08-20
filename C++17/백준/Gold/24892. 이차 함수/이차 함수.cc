#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll modPow(ll a, ll val) {
    ll res = 1;
    while (val > 0) {
        if (val & 1) res = res * a % MOD;
        a = a * a % MOD;
        val /= 2;
    }
    return res;
}

ll modInv(ll a) {
    return modPow(a, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll a, b;
    cin >> n >> a >> b;

    ll p = 0, q = 1; 
    q = 2LL * n * n * n;

    ll gp = b - a;

    for (int i = 0; i < n; i++) {
        ll x1 = a * n + gp * i;
        ll x2 = a * n + gp * (i + 1);

        ll y1 = (x1 - a * n) * (x1 - b * n);
        ll y2 = (x2 - a * n) * (x2 - b * n);

        ll sum = x1 * y2 - x2 * y1;
        p += sum;
    }

    if(p<0) p=-p;

    p %= MOD;
    q %= MOD;

    cout << p * modInv(q) % MOD;
}