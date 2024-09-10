#include<iostream>
#include<vector>
using namespace std;
vector<int> d(100004), v(100004);
int f(int x) {
    if (x == d[x]) return x;  
    int p = f(d[x]);  
    v[x] += v[d[x]]; 
    return d[x] = p; 
}
void g(int x, int y, int w) {
    int X = f(x), Y = f(y);
    if (X != Y) { 
        v[Y] = v[x] - v[y] + w; 
        d[Y] = X; 
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break; 
        for (int i = 1; i <= n; i++) {
            d[i] = i;
            v[i] = 0; 
        }
        for (int i = 0; i < m; i++) {
            char c;
            cin >> c;
            if (c == '!') {
                int x, y, w;
                cin >> x >> y >> w;
                g(x, y, w);
            }
            else if (c == '?') {
                int x, y;
                cin >> x >> y;
                if (f(x) == f(y)) cout << v[y] - v[x] << '\n'; 
                else cout << "UNKNOWN\n";
            }
        }
    }
}