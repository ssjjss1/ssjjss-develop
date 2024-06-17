#include <iostream>
using namespace std;
string k[51];
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int n;
bool f(int a, int b) {
    char c = k[a][b];
    for(int i = 0; i < 8; i++) {
        if(a + 2 * dy[i] < 0 || a + 2 * dy[i] > n || b + 2 * dx[i] < 0 || b + 2 * dx[i] > n) continue;

        if(c == k[a + dy[i]][b + dx[i]] && c == k[a + 2 * dy[i]][b + 2 * dx[i]]) {
            cout << c << endl;
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> k[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(k[i][j] != '.') {
                if(f(i, j)) return 0;
                else continue;
            }
        }
    }
    cout << "ongoing";
}