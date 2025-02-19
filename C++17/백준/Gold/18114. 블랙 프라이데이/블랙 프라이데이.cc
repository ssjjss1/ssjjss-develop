#include <bits/stdc++.h>
using namespace std;

int n, c;
int d[5004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (d[i] == c) {
            cout << 1;
            return 0;
        }
    }

    sort(d + 1, d + n + 1);

    for (int i = 1; i <= n; i++) {
        int l = i + 1, r = n;
        while (l < r) {
            int sum = d[i] + d[l] + d[r];
            if (sum == c) {
                cout << 1;
                return 0;
            }
            if (sum < c) l++;
            else r--;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (binary_search(d + i + 1, d + n + 1, c - d[i])) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}