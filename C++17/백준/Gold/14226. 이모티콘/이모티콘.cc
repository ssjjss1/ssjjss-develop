#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n;
int visited[1004][1004];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    queue<pair<int, int>> q;
    visited[1][0] = 1;
    q.push({ 1, 0 });
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        int t = visited[x][y];
        if (x == n) {
            cout << t - 1 << '\n';
            return 0;
        }
        if (visited[x][x] == 0) {
            visited[x][x] = t + 1;
            q.push({ x, x });
        }
        if (y > 0 && x + y <= n && visited[x + y][y] == 0) {
            visited[x + y][y] = t + 1;
            q.push({ x + y, y });
        }
        if (x > 1 && visited[x - 1][y] == 0) {
            visited[x - 1][y] = t + 1;
            q.push({ x - 1, y });
        }
    }
}