#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int a[104][104];
int visited[104][104];
int d[14];
vector<pair<int, pair<int, int>>> v;
const int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
int f(int x) {
    if (x == d[x]) return x;
    return d[x] = f(d[x]);
}
void g(int x, int y) {
    x = f(x), y = f(y);
    if (x != y) d[x] = y;
}
void bfs(int x, int y, int cnt) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = cnt;
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 1 && visited[nx][ny] == 0) {
                visited[nx][ny] = cnt;
                q.push({ nx, ny });
            }
        }
    }
}
void makebridge(int x, int y, int dir, int k) {
    int l = 0;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= n || y < 0 || y >= m) return; 
        if (visited[x][y] == k) return; 
        if (visited[x][y] > 0) {  
            if (l > 1) v.push_back({ l, {k, visited[x][y]} });
            return;
        }
        l+=1;
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 && visited[i][j] == 0) {
                bfs(i, j, ++cnt);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] != 0) {
                for (int k = 0; k < 4; k++) {
                    makebridge(i, j, k, visited[i][j]);
                }
            }
        }
    }
    for (int i = 1; i <= cnt; i++) d[i] = i;
    sort(v.begin(), v.end());
    int ans = 0, cn = 0;
    for (auto i : v) {
        int x = i.second.first, y = i.second.second, z = i.first;
        if (f(x) != f(y)) {
            g(x, y);
            ans += z;
            cn+=1;
        }
    }
    if (cn != cnt - 1) cout << -1 << '\n';
    else cout << ans << '\n';
}