#include <bits/stdc++.h>
using namespace std;

long long n, m;
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    while (n) {
        long long r = n % m;
        if (r < 10) s += char('0' + r);
        else s += char('A' + (r - 10));
        n /= m;
    }

    reverse(s.begin(), s.end());
    cout << s;
}