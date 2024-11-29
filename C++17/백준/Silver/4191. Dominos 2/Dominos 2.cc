#include<bits/stdc++.h>
using namespace std;

int t;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--) {
        int cnt = 0;
        int n, m, l;
        cin >> n >> m >> l;
        vector<vector<int>> v(10004); 
        vector<int> visited(10004, 0);
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
        }
        for (int i = 1; i <= l; i++) {
            int first;
            cin >> first;
            if (!visited[first]) {
                visited[first] = 1;
                queue<int> q;
                q.push(first);
                while (!q.empty()) {
                    int cx = q.front();
                    q.pop();
                    cnt += 1;
                    for (auto i : v[cx]) {
                        if (!visited[i]) {
                            q.push(i);
                            visited[i] = 1;
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}