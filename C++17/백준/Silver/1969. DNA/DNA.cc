#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
string a[1001],ans;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < m; i++) {
        map<char, int> m;
        for (int j = 0; j < n; j++)m[a[j][i]]++;
        char c;
        int max=0;
        for (auto p : m) {
            if (max < p.second) {
                max = p.second;
                c = p.first;
            }
        }
        ans += c;
        sum += n-max;
    }
    cout << ans << '\n' << sum;
}