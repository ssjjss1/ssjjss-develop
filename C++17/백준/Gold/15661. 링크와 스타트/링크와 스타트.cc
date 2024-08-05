#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long int ll;
const ll inf = 1e18+4;
ll n, ans = inf;
int d[24][24];
ll f(const vector<ll>& v, const vector<ll>& v1) {
    int x = 0, y = 0;
    int size_v = v.size();
    int size_v1 = v1.size();
    for(int i = 0; i < size_v; i++) {
        for(int j = 0; j < size_v; j++) {
            if (i == j) continue;
            x += d[v[i]][v[j]];
        }
    }
    for(int i = 0; i < size_v1; i++) {
        for(int j = 0; j < size_v1; j++) {
            if (i == j) continue;
            y += d[v1[i]][v1[j]];
        }
    }
    return abs(x - y);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    for(int i = 0; i < (1 << n); i++) {
        //if(__builtin_popcount(i) != n / 2) continue;
        vector<ll> v, v1;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) v.push_back(j);
            else v1.push_back(j);
        }
        ans = min(ans, f(v, v1));
    }
    cout << ans ;
}