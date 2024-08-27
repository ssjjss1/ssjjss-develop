#include<bits/stdc++.h>
using namespace std;
int n;
long long d[104];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) {
        vector<long long> v;
        v.push_back(d[i]);
        while (v.size() < n) {
            long long t = v.back();
            bool flag = 0;
            for (int j = 0; j < n; j++) {
                if (d[j] == t * 2 || (t % 3 == 0 && d[j] == t / 3)) {
                    v.push_back(d[j]);
                    flag = 1;
                    break;
                }
            }
            if (!flag) break;
        }
        if (v.size() == n) {
            for (long long x : v) cout << x << " ";
            return 0;
        }
    }
}