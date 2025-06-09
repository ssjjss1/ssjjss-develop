#include <bits/stdc++.h>
using namespace std;

const int DIFF = 10000;
const int SIZE = 20001;
const int INF = 1e9;

int n, m;
vector<int> d;
int visited[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    if (m == 0) {
        cout << "0\n";
        return 0;
    }

    if (n == 0) {
        cout << "-1\n";
        return 0;
    }

    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    fill(visited, visited + SIZE, INF);
    queue<int> q;

    visited[DIFF] = 0;
    q.push(DIFF);

    while (!q.empty()) {
        int x = q.front(); q.pop();

        for (auto i : d) {
            if (i == 0) continue;
            int nx = x + i;
            if (nx < 0 || nx >= SIZE) continue;

            if (visited[nx] > visited[x] + 1) {
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
    }

    int ans = visited[m + DIFF];
    cout << (ans == INF ? -1 : ans);
}