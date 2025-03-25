#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long> p;

set<long long> s[20004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<p> v(n);

        for (int i = 0; i < 20004; i++) s[i].clear();
        
        for (int i = 0; i < n; i++) {
            long long a, b;
            cin >> a >> b;
            a += 10000;
            b += 10000;
            v[i] = {a, b};
            s[a].insert(b);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p p1 = v[i], p2 = v[j];
                int x1 = p1.first, y1 = p1.second;
                int x2 = p2.first, y2 = p2.second;

                long long xm = x1 + x2, ym = y1 + y2;
                long long dx = x1 - x2, dy = y1 - y2;

                if ((xm - dy) % 2 || (ym + dx) % 2 || (xm + dy) % 2 || (ym - dx) % 2) continue;
                else {
                      long long x3 = (xm - dy) / 2, y3 = (ym + dx) / 2;
                long long x4 = (xm + dy) / 2, y4 = (ym - dx) / 2;

                if (x3 >= 0 && x3 <= 20000 && y3 >= 0 && y3 <= 20000 &&
                    x4 >= 0 && x4 <= 20000 && y4 >= 0 && y4 <= 20000) {
                          if(s[x3].count(y3) && s[x4].count(y4)){
                                ans = max(ans, (dx * dx + dy * dy) / 2);
                          }
                }
                }
            }
        }
        cout << ans << "\n";
    }
}