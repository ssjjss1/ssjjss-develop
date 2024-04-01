#include<iostream>
using namespace std;
typedef long long int ll;
const int inf = 1000000000;
ll n, m, ans = 1;
ll a[1001], b[1001];
ll f(ll x, ll y) {
  if(y==0) return x;
  return f(y,x%y);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll k;
            if (a[i] < b[j]) k = f(a[i], b[j]);
            else k = f(b[j], a[i]);
            ans *= k;
            a[i] /= k;
            b[j] /= k;
            if (ans >= inf) { 
                ans %= inf;
                flag = true;
            }

        }
    }
    if (flag) printf("%09lld", ans);
    else cout << ans;
}