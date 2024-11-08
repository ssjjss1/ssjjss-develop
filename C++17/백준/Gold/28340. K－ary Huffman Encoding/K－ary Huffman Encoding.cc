#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    LL t;
    cin >> t;
    while (t--) {
        LL n, k;
        cin >> n >> k;
        priority_queue<LL, vector<LL>, greater<LL>> q;
        for (LL i = 0, x; i < n; i++) {
            cin >> x;
            q.push(x);  
        }
        LL ans = 0;
        int mod = (q.size() - 1) % (k - 1);
        if (mod != 0) for (int i = 0; i < (k - 1 - mod); i++) q.push(0);
        while (q.size() > 1) {
            LL sum = 0;
            for (int i = 0; i < k && !q.empty(); i++) {
                sum += q.top();
                q.pop();
            }
            ans += sum;
            q.push(sum);
        }
        cout << ans << "\n";
    }
}