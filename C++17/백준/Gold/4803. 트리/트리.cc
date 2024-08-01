#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool f(int a, int n, vector<int> v[], vector<int>& visited) {
    queue<pair<int, int>> q;
    visited[a] = 1;
    q.push({ a, 0 });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i : v[x]) {
            if (!visited[i]) {
                visited[i] = 1;
                q.push({ i, x });
            }
            else if (i != y) return 1;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int k = 1;; k++) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        vector<int> visited(n + 1, 0);
        vector<int> v[300004];
        for (int i = 1, x, y; i <= m; i++) {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (!f(i, n, v, visited)) {
                    queue<int> q;
                    q.push(i);
                    visited[i] = 1;
                    while (!q.empty()) {
                        int x = q.front();
                        q.pop();
                        for (int j : v[x]) {
                            if (!visited[j]) {
                                visited[j] = 1;
                                q.push(j);
                            }
                        }
                    }
                    cnt+=1;
                }
            }
        }
        if (cnt == 0) cout << "Case " << k << ": No trees.\n";
        else if (cnt == 1) cout << "Case " << k << ": There is one tree.\n";
        else cout << "Case " << k << ": A forest of " << cnt << " trees.\n";
    }
}