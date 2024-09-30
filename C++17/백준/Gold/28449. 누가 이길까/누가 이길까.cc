#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int a[100004], b[100004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    long long A = 0, B = 0, M = 0;
    for (int i = 1; i <= m; i++) {
        int a1 = lower_bound(a + 1, a + n + 1, b[i]) - (a + 1);
        int b1 = n - (upper_bound(a + 1, a + n + 1, b[i]) - (a + 1)); 
        int m1 = (upper_bound(a + 1, a + n + 1, b[i]) - lower_bound(a + 1, a + n + 1, b[i])); 
        A += a1;
        B += b1;
        M += m1;
    }
    cout << B << " " << A << " " << M ;
}