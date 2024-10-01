#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
int d[100004], sqrt_d[100004 / 300 + 4];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i <= n / 300; i++) sqrt_d[i] = 1e9; 
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sqrt_d[i / 300] = min(sqrt_d[i / 300], d[i]);
    }
    cin >> m;
    while (m--) {
        int x, y, z;
        cin >> x;
        if (x == 1) {
            cin >> y >> z;
            y-=1;
            d[y] = z;
            int mn = 1e9+4;
            for (int i = (y / 300) * 300; i < min((y / 300) * 300 + 300, n); i++) {
                mn = min(mn, d[i]);
            }
            sqrt_d[y / 300] = mn;
        } 
        else {
            cin >> y >> z;
            y-=1; z-=1;
            int ans = 1e9+4;
            for (int i = y; i <= z;) {
                if (i % 300 == 0 && i + 300 - 1 <= z) {
                    ans = min(ans, sqrt_d[i / 300]);
                    i += 300;
                } 
                else { 
                    ans = min(ans, d[i]);
                    i+=1;
                }
            }
            cout << ans << "\n";
        }
    }
}