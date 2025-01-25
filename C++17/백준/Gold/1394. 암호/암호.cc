#include <bits/stdc++.h>
#define MOD 900528
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    vector<long long> d(265, 0);
    long long ans = 0;
    long long size=s1.size();

    for (int i = 0; i < size; i++) {
        int idx = s1[i] - '!';
        if (d[idx] == 0) {
            d[idx] = i + 1;
        }
    }

    for (int i = 0; i < s2.length(); i++) {
        int idx = s2[i] - '!';
        ans = (ans * size + d[idx]) % MOD;
    }
    cout << ans;
}