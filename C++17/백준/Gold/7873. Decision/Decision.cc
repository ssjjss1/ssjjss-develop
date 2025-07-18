#include<bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
vector<int> dir[14];

void Init() {
    for (int idx = 0; idx < 4; idx++) {
        dir[idx + 1].push_back(idx % 4);
        dir[idx + 1].push_back((idx + 1) % 4);
    }
    dir[5].push_back(0);
    dir[5].push_back(1);
    dir[5].push_back(2);
    dir[5].push_back(3);
}

void bfs(vector<vector<int>> &d, vector<vector<bool>> &visited, int n, int m, int x, int y) {
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto i : dir[d[cx][cy]]) {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (d[nx][ny] == 0) continue;
            bool flag=false;
            for(auto j:dir[d[nx][ny]]){
                  int px=nx+dx[j], py=ny+dy[j];
                  if(px==cx&&py==cy) {
                        flag=true;
                        break;
                  }
            }
            if(!flag) continue;
            
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

void run() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> d(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            d[i][j] = c - 'A';
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && d[i][j] != 0) {
                bfs(d, visited, n, m, i, j);
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    Init();
    while (t--) {
        run();
    }
}