#include<iostream>
#include<map>
using namespace std;
int n;
map<int, int> ma;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        if (x == 1) {
            int mx = -1e8;
            for (int i = y; i < y + 4; i++) mx = max(mx, ma[i]);
            for (int i = y; i < y + 4; i++) {
                if (ma[i] != 0) ma[i] = max(ma[i], mx + 1);
                else ma[i] = mx + 1;
            }
        }
        if (x == 2) ma[y] += 4;
        if (x == 3) cout << ma[y] << "\n";
    }
}