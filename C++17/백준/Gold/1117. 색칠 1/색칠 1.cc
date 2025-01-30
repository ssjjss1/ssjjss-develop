#include <bits/stdc++.h>
using namespace std;
long long w, h, f, c, x1, yy1, x2, y2;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> w >> h >> f >> c >> x1 >> yy1 >> x2 >> y2;

    long long total = w * h;
    long long folded = min(f, w - f);
    long long painted = (x2 - x1) * (y2 - yy1) * (c + 1);
    
    if (x1 < folded) painted += (min(folded, x2) - x1) * (y2 - yy1) * (c + 1);
    
    cout << total - painted;
}