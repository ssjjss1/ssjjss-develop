#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> P_S, P_F;
vector<vector<char>> d;
vector<vector<int>> trash, near_trash;
vector<vector<bool>> visited;

const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void dij() {
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
    pq.push({0, 0, P_S.first, P_S.second});
    trash[P_S.first][P_S.second] = 0;
    near_trash[P_S.first][P_S.second] = 0;

    while (!pq.empty()) {
        auto [cur_trash, cur_near_trash, x, y] = pq.top();
        pq.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || visited[nx][ny]) continue;

            int add_trash = (d[nx][ny] == 'g') ? 1 : 0;
            int add_near_trash = 0;

            if (d[nx][ny] != 'F' && d[nx][ny] == '.') {
                for (int j = 0; j < 4; j++) {
                    int nnx = nx + dx[j], nny = ny + dy[j];
                    if (nnx >= 1 && nnx <= n && nny >= 1 && nny <= m && d[nnx][nny] == 'g') {
                        add_near_trash = 1;
                        break;
                    }
                }
            }

            int new_trash = cur_trash + add_trash;
            int new_near_trash = cur_near_trash + add_near_trash;

            if (new_trash < trash[nx][ny] || (new_trash == trash[nx][ny] && new_near_trash < near_trash[nx][ny])) {
                trash[nx][ny] = new_trash;
                near_trash[nx][ny] = new_near_trash;
                pq.push({new_trash, new_near_trash, nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    d.assign(n + 4, vector<char>(m + 4, '.'));
    trash.assign(n + 4, vector<int>(m + 4, INT_MAX));
    near_trash.assign(n + 4, vector<int>(m + 4, INT_MAX));
    visited.assign(n + 4, vector<bool>(m + 4, false));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> d[i][j];
            if (d[i][j] == 'S') P_S = {i, j}, d[i][j] = '.';
            if (d[i][j] == 'F') P_F = {i, j}, d[i][j] = '.';
        }
    }

    dij();
    
    for(int i=0;i<4;i++) if(d[P_F.first+dx[i]][P_F.second+dy[i]]=='g') {
          near_trash[P_F.first][P_F.second]-=1;
          break;
    }
    
    cout << trash[P_F.first][P_F.second] << " " << near_trash[P_F.first][P_F.second];
}
