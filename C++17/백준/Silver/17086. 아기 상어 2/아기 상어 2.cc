#include<bits/stdc++.h>
using namespace std;
const int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 }, dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int n, m;
int d[54][54];
int visited[54][54];
void f() {
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[i][j] == 1) {
                q.push({ i, j });
                visited[i][j] = 0; 
            }
            else visited[i][j] = -1; 
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
            if (visited[xx][yy] != -1) continue; 
            visited[xx][yy] = visited[x][y] + 1;
            q.push({ xx, yy });  
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> d[i][j];
        }
    }
    f();
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mx = max(mx, visited[i][j]);
        }
    }
    cout << mx;
}