#include<bits/stdc++.h>
using namespace std;
int m, k, n;
vector<int> v;

double comb(int a, int b) {
    double res = 1;
    for (int i = 0; i < b; i++) {
        res *= (a - i);
        res /= (b - i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m;
    n = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        n += x;
    }
    cin >> k;
    
    double total = comb(n, k);
    double way = 0;
    
    for (int i = 0; i < m; i++) {
        if (v[i] >= k) way += comb(v[i], k);
    }
    
    cout << fixed << setprecision(9) << (way / total);
}