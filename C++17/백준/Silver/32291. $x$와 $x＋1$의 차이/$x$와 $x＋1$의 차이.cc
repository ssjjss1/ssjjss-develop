#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long x;
    cin >> x;

    long long n = x + 1;
    vector<long long> v;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i <= x) v.push_back(i);
            if (n / i <= x && i != n / i) v.push_back(n / i);
        }
    }

    sort(v.begin(), v.end());

    for (long long i : v) {
        cout << i << " ";
    }
}