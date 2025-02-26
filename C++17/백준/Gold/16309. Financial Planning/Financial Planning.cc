#include <bits/stdc++.h>
using namespace std;

long long n, m;

struct T {
    long long a, b;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector<T> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b;
    }

    long long l = 0, r = 2e9, ans = -1; 
    while (l <= r) {
        long long middle = (l + r) / 2;
        long long sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += max(0LL, v[i].a * middle - v[i].b);
            if (sum >= m) break; 
        }
        
        if (sum >= m) {
            ans = middle;
            r = middle - 1;
        } else {
            l = middle + 1;
        }
    }
    
    cout << ans;
}