#include<iostream>
#include<vector>
using namespace std;
int n, m;
bool d[201][201];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = d[b][a] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (d[i][j]) continue;
            for (int k = j + 1; k <= n; k++) {
                if (d[i][k] || d[j][k]) continue;
                cnt+=1; 
            }
        }
    }
    cout << cnt;
}