#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int d[6];
vector<int> v[6];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 5; i++) cin >> d[i];
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        v[x].push_back(y);
    }
    for (int i = 1; i <= 5; i++) sort(v[i].begin(), v[i].end());
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < d[i]; j++) {
            if (j == 0) {
                sum += v[i][j];
            } else {
                sum += v[i][j];
                sum += v[i][j] - v[i][j - 1];
            }
        }
        if (i < 5) sum += 60;
    }
    cout << sum;
}