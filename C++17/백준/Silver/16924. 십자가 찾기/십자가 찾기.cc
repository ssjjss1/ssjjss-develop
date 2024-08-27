#include<iostream>
#include<vector>
using namespace std;
int n, m;
const int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
char c[104][104];
int visited[104][104];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    vector<pair<pair<int, int>, int>> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '*') {
                int k = 0;
                while (true) {
                    k++;
                    bool flag = true;
                    for (int p = 0; p < 4; p++) {
                        int nx = i + dx[p] * k;
                        int ny = j + dy[p] * k;
                        if (nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] != '*') {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        v.push_back({ {i, j}, k });
                    } else {
                        break;
                    }
                }
            }
        }
    }
    for (auto i : v) {
        int x = i.first.first, y = i.first.second;
        visited[x][y] = 1; 
        for (int j = 1; j <= i.second; j++) {
            for (int k = 0; k < 4; k++) {
                visited[x + dx[k] * j][y + dy[k] * j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '*' && !visited[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << v.size() << "\n";
    for (auto i : v) {
        cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
    }
}