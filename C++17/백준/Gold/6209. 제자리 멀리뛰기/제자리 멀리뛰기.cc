#include<bits/stdc++.h>
using namespace std;
long long d, n, m;
vector<long long> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> d >> n >> m;
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    v.push_back(0);
    v.push_back(d);
    sort(v.begin(), v.end());
    
    long long l = 0, r = d, ans = 0;
    while (l <= r) {
        long long middle = (l + r) / 2;
        long long cnt = 0, idx = 0;
        
        for (int i = 1; i < v.size(); i++) {
            if (v[i] - v[idx] < middle) cnt+=1;
            else idx = i;
        }
        
        if (cnt > m) r = middle - 1;
        else ans = middle, l = middle + 1;
    }
    cout << ans;
}