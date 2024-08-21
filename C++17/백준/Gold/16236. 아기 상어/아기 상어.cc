#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int n;
pair<int, int> p;
int ss = 2, cnt = 0;
int visited[24][24], d[24][24];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
            if (d[i][j] == 9) {
                d[i][j] = 0;
                p.first = i;
                p.second = j;
            }
        }
    }
    int ans = 0;
    while (true) {
        fill(&visited[0][0], &visited[0][0] + 24 * 24, 0);
        queue<pair<int, int>> q;
        vector<pair<int, pair<int, int>>> v;
        q.push({ p.first, p.second });
        visited[p.first][p.second] = 1;
        bool flag = 0;
        int mn = 1e9;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 1 || yy < 1 || xx > n || yy > n || visited[xx][yy]) continue;
                visited[xx][yy] = visited[x][y] + 1;
                if (d[xx][yy] > 0 && d[xx][yy] < ss) {
                    flag = 1;
                    if (visited[xx][yy] < mn) {
                        v.clear();
                        mn = visited[xx][yy];
                    }
                    if (visited[xx][yy] == mn) {
                        v.push_back({ xx, {yy, visited[xx][yy]} });
                    }
                }
                if (d[xx][yy] == 0 || d[xx][yy] == ss) q.push({ xx, yy });
            }
        }
        if (v.empty()) break;
        sort(v.begin(), v.end());
        int x = v[0].first, y = v[0].second.first;
        p.first = x;
        p.second = y;
        d[x][y] = 0;
        ans += (visited[x][y] - 1);
        cnt+=1;
        if (cnt == ss) {
            ss+=1;
            cnt = 0;
        }
    }
    cout << ans;
}