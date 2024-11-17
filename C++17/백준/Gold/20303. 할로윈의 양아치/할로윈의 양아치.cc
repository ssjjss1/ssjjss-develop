#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
vector<long long> parent(30004), d(30004), sum(30004, 0), Size(30004, 0);
vector<long long> dp(30004, 0);
int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void unionSets(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) parent[y] = x;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        unionSets(x, y);
    }
    for (int i = 1; i <= n; i++) {
        int p = find(i);
        sum[p] += d[i];
        Size[p]+=1;
    }
    for (int i = 1; i <= n; i++) {
        if (Size[i] > 0) {
            for (int j = k - 1; j >= Size[i]; j--) {
                dp[j] = max(dp[j], dp[j - Size[i]] + sum[i]);
            }
        }
    }
    cout << dp[k - 1];
}