#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[1004][1004];
char d[1004][1004];
int dx[256], dy[256];
int ans;

void dfs(int x, int y) {
    visited[x][y] = 1;
    int nx = x + dx[d[x][y]];
    int ny = y + dy[d[x][y]];

    if (!visited[nx][ny]) {
        dfs(nx, ny);
    } else if (visited[nx][ny] == 1) {
        ans+=1;
    }

    visited[x][y] = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    dx['U'] = -1; dy['U'] = 0;
    dx['D'] = 1;  dy['D'] = 0;
    dx['L'] = 0;  dy['L'] = -1;
    dx['R'] = 0;  dy['R'] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> d[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
            }
        }
    }

    cout << ans;
}