#include<iostream>
#include<algorithm>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int mx[3] = { 0, 0, 0 };
    int mn[3] = { 0, 0, 0 };
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        int pmx[3] = { mx[0], mx[1], mx[2] };
        int pmn[3] = { mn[0], mn[1], mn[2] };
        mx[0] = max(pmx[0], pmx[1]) + a;
        mx[1] = max({ pmx[0], pmx[1], pmx[2] }) + b;
        mx[2] = max(pmx[1], pmx[2]) + c;
        mn[0] = min(pmn[0], pmn[1]) + a;
        mn[1] = min({ pmn[0], pmn[1], pmn[2] }) + b;
        mn[2] = min(pmn[1], pmn[2]) + c;
    }
    int ans1= max({ mx[0], mx[1], mx[2] });
    int ans2 = min({ mn[0], mn[1], mn[2] });
    cout << ans1 << " " << ans2;
}