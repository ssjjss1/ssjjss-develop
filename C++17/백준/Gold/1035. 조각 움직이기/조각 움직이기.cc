#include <bits/stdc++.h>
using namespace std;
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int ans = 1e9+7;
vector<pair<int, int>> v;
bool check(const vector<pair<int, int>>& pos) {
    if (pos.empty()) return false;
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push(pos[0]);
    visited.insert(pos[0]);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (visited.count({nx, ny}) == 0 && 
                find(pos.begin(), pos.end(), make_pair(nx, ny)) != pos.end()) {
                visited.insert({nx, ny});
                q.push({nx, ny});
            }
        }
    }
    return visited.size() == pos.size();
}
int dist(vector<pair<int, int>> target) {
    int total = 0;
    for (int i = 0; i < v.size(); i++) {
        total += abs(v[i].first - target[i].first) + abs(v[i].second - target[i].second);
    }
    return total;
}
void dfs(int idx, vector<pair<int, int>>& cur) {
    if (idx == v.size()) {
        if (check(cur)) ans = min(ans, dist(cur));
        return;
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (find(cur.begin(), cur.end(), make_pair(i, j)) == cur.end()) {
                cur.push_back({i, j});
                dfs(idx + 1, cur);
                cur.pop_back();
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            char c; cin >> c;
            if (c == '*') v.push_back({i, j});
        }
    }
    if (v.empty()||v.size()==1) {
        cout << 0 ;
        return 0;
    }
    vector<pair<int, int>> cur;
    dfs(0, cur);
    cout << ans ;
}