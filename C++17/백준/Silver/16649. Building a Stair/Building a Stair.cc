#include <bits/stdc++.h>
using namespace std;
int n;
char c[50][50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int p = 50, size = 0;
    vector<int> v;
    while (true) {
        int N = n;
        v.clear();
        for (int i = p; i >= 1; i--) {
            if (N >= (2 * i - 1)) {
                N -= (2 * i - 1);
                v.push_back(i);
            }
        }
        if (N == 0) {
            size = v[0];
            for (int i = 0; i < size; i++) 
                for (int j = 0; j < size; j++) 
                    c[i][j] = '.';
            
            for (int i = 0; i < v.size(); i++) {
                int I = size - 1 - i;
                for (int j = 0; j < v[i]; j++) {
                    c[I][j] = 'o';
                }
                for (int j = I; j > I - v[i]; j--) {
                    c[j][i] = 'o';
                }
            }
            
            cout << size << '\n';
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    cout << c[i][j];
                }
                cout << '\n';
            }
            return 0;
        }
        p -= 1;
        if (p == 0) break;
    }
    cout << -1;
}