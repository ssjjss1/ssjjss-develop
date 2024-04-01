#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
ll n, mx;
int m, q;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> q >> m;
    vector<long long int> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    vector<int> v;
    vector<int> v1;
    v.push_back(1),v.push_back(1),v1.push_back(1),v1.push_back(1);
  long long int size;
    for (ll i = 2; i < mx; i++) {
        ll k = ((v[i - 1] + v[i - 2]) % m);
        v.push_back(k);
        vector<int> v2;
        if (k == 0) {
            v1.push_back(k);
            continue;
        }
        ll p = k;
        for (;;) {
            if (p <= 0) break;
            v2.push_back(p % 10);
            p /= 10;
        }
        for (int j = v2.size() - 1; j >= 0; j--) {
            v1.push_back(v2[j]);
        }
        if (v[i] == 1 && v[i - 1] == 1&&i>2) {
            size = v1.size() - 2;
            break;
        }
    }
    for (ll i = 0; i < q; i++) {
        int ans;
        if(size!=0) ans=(a[i]-1)%size;
        else ans=a[i]-1;
        cout<<v1[ans]<<"\n";
    }
    return 0;
}
