#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    unordered_map<long long, long long> m;
    int l = 0, r = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ')') {
            if (l > 0) l -= 1;
            else r += 1;
        }
        else {
            l += 1;
        }
        if (r > 0) break;
        m[l] += 1;
    }

    long long ans = 0;
    l = r = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == ')') {
            if (l > 0) l-=1;
            else r+=1;
        }
        else {
            l+=1;
        }
        if (l == 0) ans += m[r];
    }

    cout << ans;
}