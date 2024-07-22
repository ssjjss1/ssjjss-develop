#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int n, m, k, a, b;
ll sum;
ll dp[1004][1004];
const ll inf = 1e18 + 4;
vector<pair<ll, ll>> v[30004];
struct P {
    ll c, d, e;
};
void f(int s) {
    queue<P> q;
    q.push({s, 0, 0});
    fill(&dp[0][0], &dp[0][0] + 1004 * 1004, inf);
    dp[s][0] = 0;
    while (!q.empty()) {
        ll x = q.front().c, y = q.front().d, cnt = q.front().e;
        q.pop();
        if (dp[x][cnt] < y) continue;
        for (auto i : v[x]) {
            ll xx = i.first, yy = i.second;
            if (cnt + 1 <= 1003 && dp[xx][cnt + 1] > y + yy) {
                dp[xx][cnt + 1] = y + yy;
                q.push({xx, y + yy, cnt + 1});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> a >> b;
    for (int i = 1, x, y, z; i <= m; i++) {
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    f(a); 
    ll mn = inf;
    for (int i = 0; i <= n; i++) mn = min(mn, dp[b][i]);
    cout << mn << "\n";
    while (k--) {
        int x;
        mn = inf;
        cin >> x;
        sum += x;
        for (int i = 0; i <= n; i++) mn = min(mn, dp[b][i] + sum * i);
        cout << mn << "\n";
    }
}