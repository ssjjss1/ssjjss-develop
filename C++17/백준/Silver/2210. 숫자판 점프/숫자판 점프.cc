#include <iostream>
#include <map>
using namespace std;
int d[14][14];
map<int, int> ma;
const int dx[4] = { 1, -1, 0, 0 },dy[4] = { 0, 0, 1, -1 };
void f(int x, int y, int num, int cnt) {
    if (cnt == 6) {
        ma[num]+=1;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            f(nx, ny, num * 10 + d[nx][ny], cnt + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            f(i, j, d[i][j], 1);
        }
    }
    cout << ma.size();
}