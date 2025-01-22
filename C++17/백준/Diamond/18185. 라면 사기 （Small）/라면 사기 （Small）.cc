#include<bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> v(n+4);
    for (int i = 0; i < n; i++) cin >> v[i];
    int cx = 0;
    while (cx < n) {
        if (cx < n && v[cx]) {
            v[cx] -= 1;
            ans += 3;
            if (cx + 1 < n && v[cx + 1]) {
                int t = v[cx + 1];
                v[cx + 1] -= 1;
                ans += 2;
                if (cx + 2 < n && v[cx + 2]) {
                    if (v[cx + 2] >= t) {
                        v[cx + 2] -= 1;
                        ans += 2;
                    }
                }
            }
        } else cx+=1;
    }
    cout << ans;
}