#include<iostream>
#include<algorithm>
using namespace std;
int n, c, ans;
int d[200004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> d[i];
    sort(d + 1, d + n + 1);
    int l = 1, r = d[n] - d[1];
    while (l <= r) {
        int mid = (l + r) / 2, cnt = 1; 
        int k = d[1]; 
        for (int i = 2; i <= n; i++) {
            if (d[i] - k >= mid) {
                cnt++;
                k = d[i]; 
            }
        }
        if (cnt >= c) {
            ans = mid;
            l = mid + 1;
        } 
        else r = mid - 1; 
    }
    cout << ans;
}