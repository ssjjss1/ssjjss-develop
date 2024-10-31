#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 1e9+7;
int N, M, K, X;
vector<int> v[300004];
vector<int> visited, ans;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K >> X;
    visited.resize(N + 4, INF);
    for (int i = 1, x, y; i <= M; i++) {
        cin >> x >> y;
        v[x].push_back(y);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    visited[X] = 0; 
    q.push({0, X});
    while (!q.empty()) {
        int y = q.top().first, x = q.top().second;
        q.pop();
        if (y > visited[x]) continue;
        for (auto i : v[x]) {
            if (visited[i] > y + 1) {
                visited[i] = y + 1;
                q.push({y + 1, i});
            }
        }
    }
    for (int i = 1; i <= N; i++) if (visited[i] == K) ans.push_back(i); 
    if (ans.empty()) cout << -1;
    else for (auto i : ans) cout << i << "\n";
}