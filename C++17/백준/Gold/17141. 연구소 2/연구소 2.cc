#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int inf=1e9+4;
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int n, m;
int a[54][54];
int d[54][54][14];
vector<pair<int, int>> v;
void f(int x, int y, int cnt) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    d[x][y][cnt] = 0;
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = cx + dx[i], yy = cy + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > n || a[xx][yy] == 1 || d[xx][yy][cnt] != -1) continue;
            d[xx][yy][cnt] = d[cx][cy][cnt] + 1;
            q.push({ xx, yy });
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) v.push_back({ i, j });
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                d[x][y][i] = -1;
            }
        }
        f(v[i].first, v[i].second, i);
    }
    vector<int> v2(v.size(), 0);
    fill(v2.begin(), v2.begin() + m, 1);
    int mn = inf;
    do {
        int mx = 0;
        vector<vector<int>> k(n + 4, vector<int>(n + 4, inf));
        for (int i = 0; i < v.size(); i++) {
            if (v2[i] == 1) {
                for (int x = 1; x <= n; x++) {
                    for (int y = 1; y <= n; y++) {
                        if (a[x][y] != 1 && d[x][y][i] != -1) {
                            k[x][y] = min(k[x][y], d[x][y][i]);
                        }
                    }
                }
            }
        }
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] != 1) {
                    if (k[i][j] == inf) {
                        flag = 0;
                        break;
                    }
                    mx = max(mx, k[i][j]);
                }
            }
            if (!flag) break;
        }
        if (flag) mn = min(mn, mx);
    } while (prev_permutation(v2.begin(), v2.end()));
    if (mn == inf)  cout << -1;
    else cout << mn;
}