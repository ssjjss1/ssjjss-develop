#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    map<pair<int, int>, int> points;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[{x, y}] = 1;
    }

    int cnt = 0;

    for (auto &[p, _] : points) {
        int x = p.first, y = p.second;
        if (points.count({x + a, y}) && points.count({x, y + b}) && points.count({x + a, y + b})) {
            cnt+=1;
        }
    }
    cout << cnt;
}