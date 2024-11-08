#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end());
    for (const auto& [x, y] : v) {
        while (!q.empty() && q.top() <= x) q.pop();
        q.push(y);
        ans = max(ans, (int)(q.size()));
    }
    cout << ans;
}