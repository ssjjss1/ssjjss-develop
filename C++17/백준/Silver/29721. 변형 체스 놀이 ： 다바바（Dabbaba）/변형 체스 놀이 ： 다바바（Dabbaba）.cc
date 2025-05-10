#include <bits/stdc++.h>
using namespace std;

const int dx[] = {2, 0, -2, 0}, dy[] = {0, 2, 0, -2};
int n, k;
map<int, map<int, int>> ma;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        ma[x][y] = 1;
    }

    int cnt = 0;
    for (auto [x, y] : v) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (ma[nx][ny]) continue;

            cnt += 1;
            ma[nx][ny] = 1;
        }
    }

    cout << cnt;
}