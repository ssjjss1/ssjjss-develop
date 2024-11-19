#include <bits/stdc++.h>
using namespace std;
int t;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<bool> key(30, 0); 
        vector<vector<char>> c(n + 4, vector<char>(m + 4, '.'));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c[i][j];
            }
        }
        string s;
        cin >> s;
        if (s != "0") for (auto i : s) key[i - 'a'] = 1; 
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n + 2, vector<int>(m + 2, 0)); 
        q.push({0, 0}); 
        visited[0][0] = 1;
        int cnt = 0; 
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && yy >= 0 && xx <= n + 1 && yy <= m + 1 && !visited[xx][yy]) {
                    char cell = c[xx][yy];
                    if (cell == '*') continue;
                    visited[xx][yy] = 1;
                    if (cell == '.') {
                        q.push({xx, yy}); 
                    } else if (cell == '$') {
                        cnt+=1;    
                        c[xx][yy] = '.'; 
                        q.push({xx, yy});
                    } else if (cell >= 'A' && cell <= 'Z') {
                        if (key[cell - 'A']) {
                            q.push({xx, yy});
                        }
                    } else if (cell >= 'a' && cell <= 'z') { 
                        if (!key[cell - 'a']) {
                            key[cell - 'a'] = 1;
                            fill(visited.begin(), visited.end(), vector<int>(m + 2, 0));
                            q = queue<pair<int, int>>();
                            q.push({xx, yy});
                        }
                        c[xx][yy] = '.';
                        q.push({xx, yy});
                    }
                }
            }
        }
        cout << cnt << "\n"; 
    }
}