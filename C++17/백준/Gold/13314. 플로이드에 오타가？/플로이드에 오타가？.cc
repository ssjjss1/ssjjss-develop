#include <bits/stdc++.h>
using namespace std;
const int MX = 100;
int main() {
    vector<vector<int>> v(104, vector<int>(104));
    for (int i = 1; i <= MX; i++) {
        for (int j = 1; j <= MX; j++) {
            if (i == j) v[i][j] = 0;
            else if (j == MX  || i == MX) v[i][j] = 1;
            else v[i][j] = 1000;
        }
    }
    cout << MX << "\n";
    for (int i = 1; i <= MX; i++) {
        for (int j = 1; j <= MX; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}