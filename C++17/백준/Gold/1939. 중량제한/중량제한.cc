#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
vector<pair<int, int>> v[10004];
int s, e;
bool f(int x) {
    vector<bool> visited(n + 4, 0);
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int cx = q.front();
        q.pop();
        if (cx == e) return 1;
        for (auto i : v[cx]) {
            int nx = i.first, w = i.second;
            if (!visited[nx] && w >= x) {
                visited[nx] = 1;
                q.push(nx);
            }
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0,x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        v[x].push_back({ y, z });
        v[y].push_back({ x, z });
    }
    cin >> s >> e;
    int l = 1, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (f(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}