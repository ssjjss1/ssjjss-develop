#include<iostream>
#include<algorithm>
using namespace std;
long long int ans = 1e18;
int n;
long long int a[1001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            long long int sum = a[i] + a[j];//안나
            int l = 1, r = n;
            for (;;) {
                bool flag = true;
                if (l == i || l == j) l += 1, flag = false;
                if (r == i || r == j) r -= 1, flag = false;
                if (l >= r) break;
                if (flag) {
                    long long int sum1 = a[l] + a[r];//엘사
                    ans = min(ans, abs(sum - sum1));
                    if (sum >= sum1) l += 1;
                    else if (sum < sum1) r -= 1;
               }
            }
        }
    }
    cout << ans;
}