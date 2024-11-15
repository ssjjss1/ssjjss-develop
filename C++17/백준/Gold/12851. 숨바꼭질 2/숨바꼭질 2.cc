#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> visited(200004, -1), cnt(200004, 0);
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    if (n == m) {
        cout << "0\n1\n";
        return 0;
    }
    queue<int> q;
    q.push(n);
    visited[n] = 0;
    cnt[n] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int next : {x * 2, x + 1, x - 1}) {
            if (next >= 0 && next <= 200000) {
                if (visited[next] == -1) {
                    visited[next] = visited[x] + 1;
                    cnt[next] = cnt[x];
                    q.push(next);
                } 
                else if (visited[next] == visited[x] + 1) cnt[next] += cnt[x];
            }
        }
    }
    cout << visited[m] << "\n" << cnt[m];
}