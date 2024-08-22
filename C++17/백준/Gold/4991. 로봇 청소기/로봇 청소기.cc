#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int n, m;
int mn;
char c[24][24];
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
pair<int, int> p;
vector<pair<int, int>> v;
vector<vector<int>> dist; 
int g(int a, int b, int aa, int bb) {
    queue<pair<int, int>> q;
    q.push({ a, b });
    vector<vector<int>> visited(n + 4, vector<int>(m + 4, 0));
    visited[a][b] = 1;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x == aa && y == bb) return visited[aa][bb] - 1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > m || c[xx][yy] == 'x' || visited[xx][yy]) continue;
            visited[xx][yy] = visited[x][y] + 1;
            q.push({ xx, yy });
        }
    }
    return -1;
}
void h() {
    dist = vector<vector<int>>(v.size() + 1, vector<int>(v.size() + 1, -1));
    for (int i = 0; i < v.size(); i++) {
        dist[0][i + 1] = g(p.first, p.second, v[i].first, v[i].second);
        for (int j = i + 1; j < v.size(); j++) {
            int d = g(v[i].first, v[i].second, v[j].first, v[j].second);
            dist[i + 1][j + 1] = d;
            dist[j + 1][i + 1] = d;
        }
    }
}
void f(int x, int bit, int ans, vector<vector<int>>& dp) {
    if (bit == (1 << v.size()) - 1) {
        mn = min(mn, ans);
        return;
    }
    if (dp[x][bit] <= ans) return;
    dp[x][bit] = ans;
    for (int i = 0; i < v.size(); i++) {
        if (bit & (1 << i)) continue;
        int d = dist[x][i + 1];
        if (d == -1) continue;
        f(i + 1, bit | (1 << i), ans + d, dp);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (true) {
        cin >> m >> n;
        if (n == 0 && m == 0) break;
        mn = INT_MAX;
        v.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c[i][j];
                if (c[i][j] == 'o') p = { i, j }, c[i][j] = '.';
                else if (c[i][j] == '*') v.push_back({ i, j }), c[i][j] = '.';
            }
        }
        h(); 
        vector<vector<int>> dp(v.size() + 1, vector<int>((1 << v.size()), INT_MAX));
        f(0, 0, 0, dp);
        if (mn == INT_MAX) cout << "-1\n";
        else cout << mn << "\n";
    }
}