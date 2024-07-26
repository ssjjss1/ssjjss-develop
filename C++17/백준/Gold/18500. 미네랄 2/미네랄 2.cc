#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int r, c;
int n;
char d[104][104];
const int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
void bfs(int x, int y, vector<pair<int, int>>& v1, vector<vector<bool>>& visited) { //bfs탐색
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = 1;
    v1.push_back({ x, y });
    while (!q.empty()) {
        int xx = q.front().first,yy=q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i], ny = yy + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && d[nx][ny] == 'x') {
                visited[nx][ny] = 1;
                q.push({ nx, ny });
                v1.push_back({ nx, ny });
            }
        }
    }
}
void dc(vector<pair<int, int>>& v1,vector<vector<bool>>& visited) { // 떨어지는 클러스터 확인
    for (auto i : v1) {
        int x = i.first, y = i.second;
        d[x][y] = '.';
    }
    while (true) {
        for (auto i : v1) {
            int x = i.first, y = i.second;
            if (x + 1 >= r || d[x + 1][y] == 'x') {
                for (auto j : v1) {
                    int xx = j.first, yy = j.second;
                    d[xx][yy] = 'x';
                }
                for(auto i:v1) visited[i.first][i.second]=1;
                return;
            }
        }
        for (auto& i : v1) i.first+=1;
    }
}
void f(int x, bool flag) {
    if (flag) {
        for (int j = 0; j < c; j++) {
            if (d[x][j] == 'x') {
                d[x][j] = '.';
                break;
            }
        }
    }
    else {
        for (int j = c - 1; j >= 0; j--) {
            if (d[x][j] == 'x') {
                d[x][j] = '.';
                break;
            }
        }
    }
}
void g() {
    vector<vector<bool>> visited(r + 4, vector<bool>(c + 4, 0));
    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            if (d[i][j] == 'x' && !visited[i][j]) {
                vector<pair<int, int>> v1;
                bfs(i, j, v1, visited);
                dc(v1, visited);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> d[i][j];
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = r - x;
        f(x, i % 2 == 0);
        g();
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << d[i][j];
        }
        cout << "\n";
    }
}