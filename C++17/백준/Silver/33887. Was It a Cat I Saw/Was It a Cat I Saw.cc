#include <bits/stdc++.h>
using namespace std;

int t;
vector<long long> v;

void palindrome(int len, string s) {
    if ((int)s.length() == len) {
        if (s.front() == '0') return;

        long long val = 0;
        for (auto i : s) {
            val = val * 2 + (i - '0');
        }
        v.push_back(val);
        return;
    }

    palindrome(len, '0' + s + '0');
    palindrome(len, '1' + s + '1');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int len = 1; len <= 32; len++) {
        if (len == 1) {
            v.push_back(1);
        } else if (len % 2 == 0) {
            palindrome(len, "11");
            palindrome(len, "00");
        } else {
            palindrome(len, "1");
            palindrome(len, "0");
        }
    }

    sort(v.begin(), v.end());

    while (t--) {
        long long n;
        cin >> n;

        auto it = lower_bound(v.begin(), v.end(), n);

        long long ans = LLONG_MAX;
        if (it != v.end()) {
            ans = min(ans, abs(*it - n));
        }
        if (it != v.begin()) {
            --it;
            ans = min(ans, abs(*it - n));
        }

        cout << ans << '\n';
    }
}