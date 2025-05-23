#include <bits/stdc++.h>
using namespace std;

int t;
bool visited[5004];
vector<int> primes;
vector<vector<int>> v(5004, vector<int>(5004, 0));

void run() {
    for (int i = 2; i <= 5000; i++) {
        if (!visited[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= 5000; j += i) {
                visited[j] = 1;
            }
        }
    }

    for (int i = 2; i <= 5000; i++) {
        v[i] = v[i - 1];
        int x = i;
        for (auto p : primes) {
            if (p > x) break;
            while (x % p == 0) {
                v[i][p]++;
                x /= p;
            }
            if (x == 1) break;
        }
        if (x > 1) v[i][x]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    run();

    while (t--) {
        int n1, r1, n2, r2;
        cin >> n1 >> r1 >> n2 >> r2;

        vector<int> A(5004, 0), B(5004, 0);

        for (auto p : primes) {
            A[p] = v[n1][p] - v[r1][p] - v[n1 - r1][p];
            B[p] = v[n2][p] - v[r2][p] - v[n2 - r2][p];
        }

        bool flag = true;
        for (auto p : primes) {
            if (A[p] > 0 && B[p] > 0) {
                cout << "0\n";
                flag = false;
                break;
            }
        }

        if (flag) cout << "1\n";
    }
}