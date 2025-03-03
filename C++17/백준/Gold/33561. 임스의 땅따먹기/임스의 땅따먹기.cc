#include <bits/stdc++.h>
using namespace std;

struct P {
    int x, y; 
};

int n, k;
int d[504][504], sum_k[1000004];
P sum[504][504];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j].x = d[i][j] + sum[i - 1][j].x + sum[i][j - 1].x - sum[i - 1][j - 1].x;
            sum[i][j].y = (d[i][j] == 0 ? 1 : 0) + sum[i - 1][j].y + sum[i][j - 1].y - sum[i - 1][j - 1].y;
        }
    }
    
    cin >> k;
    vector<int> v(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> sum_k[i];
    }

    sort(sum_k+1, sum_k+k+1, greater<>());
    
    for(int i=1;i<=k;i++) sum_k[i]+=sum_k[i-1];
    
    int ans = 0;
    
    for (int len = 0; len < n; len++) { 
        for (int i = 1; i + len <= n; i++) { 
            for (int j = 1; j + len <= n; j++) {
                int x1 = i, y1 = j;
                int x2 = i + len, y2 = j + len;
                int sum_all = sum[x2][y2].x - sum[x1 - 1][y2].x - sum[x2][y1 - 1].x + sum[x1 - 1][y1 - 1].x;
                int sum_zero = sum[x2][y2].y - sum[x1 - 1][y2].y - sum[x2][y1 - 1].y + sum[x1 - 1][y1 - 1].y;
                if (sum_zero <= k) {
                    ans = max(ans, sum_all + sum_k[sum_zero]); 
                }
            }
        }
    }

    cout << ans;
}