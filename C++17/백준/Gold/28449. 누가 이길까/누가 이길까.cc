#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int a[100004], b[100004], sum[100004];
long long a1, a2, d1;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[a[i]] += 1;
    }
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= 100000; i++) sum[i] += sum[i - 1];
    for (int i = 1; i <= m; i++) {
        a1 += (n - sum[b[i]]);
        a2 += sum[b[i] - 1];
        d1 += (sum[b[i]] - sum[b[i] - 1]);
    }
    cout << a1 << " " << a2 << " " << d1 ;
}