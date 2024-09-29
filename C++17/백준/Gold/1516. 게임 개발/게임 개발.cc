#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[504]; 
int n;
int a[504], d[504], dp[504];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (true) {
            int x;
            cin >> x;
            if (x == -1) break; 
            v[x].push_back(i);
            d[i]+=1;
        }
    }
    for (int i = 1; i <= n; i++) dp[i] = a[i];
    queue<int> q;
    for (int i = 1; i <= n; i++) if (d[i] == 0) q.push(i);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i : v[x]) {
            dp[i] = max(dp[i], dp[x] + a[i]);
            if (!--d[i]) q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) cout << dp[i] << "\n";
}