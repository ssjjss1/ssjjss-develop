#include <bits/stdc++.h>
using namespace std;

double a;
int b;
double dp[305][305];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    dp[0][0] = 1.0;
    for (int i = 1; i <= b; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] += dp[i - 1][j] * (1 - a); 
            if (j > 0) dp[i][j] += dp[i - 1][j - 1] * a;
        }
    }

    for (int i = 0; i <= b; i++) {
        double p = 0.0;
        for (int j = 0; j <= i; j++) {
            p += dp[b][j];
        }
        if (p >= 0.05) {
            cout << i;
            return 0;
        }
    }

    cout << b;
}