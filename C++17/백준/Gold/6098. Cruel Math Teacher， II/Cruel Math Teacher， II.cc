#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

ld poly(const vector<ld> &coef, ld x) {
    ld res = coef.back();
    for (int i = (int)coef.size() - 2; i >= 0; i--) {
        res = res * x + coef[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int d;
    cin >> d;
    vector<ld> coef(d + 1);
    for (int i = 0; i <= d; i++) {
        cin >> coef[i];
    }

    ld l = -1'000'000.0, r = 1'000'000.0;

    while (r - l > 1e-9) { 
        ld mid = (l + r) / 2;
        ld val = poly(coef, mid);
        ld valL = poly(coef, l);

        if ((val >= 0 && valL >= 0) || (val < 0 && valL < 0)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    ld root = (l + r) / 2;
    cout << (long long)(root * 1000.0);
}