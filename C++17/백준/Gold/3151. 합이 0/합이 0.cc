#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    long long cnt = 0;
    
    for (int i = 0; i < n - 2; i++) {
        for (int r = i + 1; r < n - 1; r++) {
            int t = -(v[i] + v[r]);
            cnt += upper_bound(v.begin() + r + 1, v.end(), t) - lower_bound(v.begin() + r + 1, v.end(), t);
        }
    }
    
    cout << cnt;
}