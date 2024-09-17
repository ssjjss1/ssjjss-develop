#include <iostream>
using namespace std;
int s, n, k, r1, r2, c1, c2;
int f(int size, int r, int c) {
    if (size == 1) return 0; 
    int size1 = size / n;
    int m_s = (n - k) / 2 * size1, m_e = m_s + k * size1;
    if (r >= m_s && r < m_e && c >= m_s && c < m_e) return 1;
    return f(size1, r % size1, c % size1);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    int size = 1;
    for (int i = 0; i < s; i++) size *= n; 
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) cout << (f(size, i, j) ? '1' : '0');
        cout << '\n'; 
    }
}