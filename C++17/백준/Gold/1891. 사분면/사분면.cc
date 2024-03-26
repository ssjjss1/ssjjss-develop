#include<iostream>
#include<cmath>
using namespace std;
typedef long long int ll;
int n;
ll x, y;
ll k;
ll e, f;
string s;
void ff(ll a, ll b, ll cnt, ll c) {
    if (cnt == n) {
        e = a, f = b;
        return;
    }
    if (s[cnt] == '1') {
        ff(a, b + c / 2, cnt + 1, c / 2);
    }
    else if (s[cnt] == '2') {
        ff(a, b, cnt + 1, c / 2);
    }
    else if (s[cnt] == '3') {
        ff(a + c / 2, b, cnt + 1, c / 2);
    }
    else if (s[cnt] == '4') {
        ff(a + c / 2, b + c / 2, cnt + 1, c / 2);
    }
}
void g(ll a, ll b, ll c, ll d, ll q) {
    if (q == 1) return;
    else if (a < q / 2 + c && b >= q / 2 + d) cout<<"1", g(a, b, c, d + q / 2, q / 2);
    else if (a < q / 2 + c && b < q / 2 + d) cout<<"2", g(a, b, c, d, q / 2);
    else if (a >= q / 2 + c && b < q / 2 + d) cout<<"3", g(a, b, c + q / 2, d, q / 2);
    else if (a >= q / 2 + c && b >= q / 2 + d) cout<<"4", g(a, b, c + q / 2, d + q / 2, q / 2);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s >> x >> y;
    k = pow(2, n);
    ff(0, 0, 0, k);
    e -= y;
    f += x;
    if (e >= 0 && e < k && f >= 0 && f < k) {
        g(e,f,0,0,k);
    }
    else cout << -1;
}