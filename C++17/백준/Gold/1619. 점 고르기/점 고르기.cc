#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    map<tuple<int, int, int>, set<int>> ma; 

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto [x1, y1] = points[i];
            auto [x2, y2] = points[j];

            int dx = x2 - x1;
            int dy = y2 - y1;

            int A = dy, B = -dx;
            int g = gcd(abs(A), abs(B));
            if (g != 0) {
                A /= g;
                B /= g;
            }

            if (A < 0 || (A == 0 && B < 0)) {
                A = -A;
                B = -B;
            }

            int C = A * x1 + B * y1;

            ma[{A, B, C}].insert(i);
            ma[{A, B, C}].insert(j);
        }
    }

    int ans = -1;
    for (auto& [_, s] : ma) {
        if ((int)s.size() >= 3) {
            ans = max(ans, (int)s.size());
        }
    }

    cout << ans;
}