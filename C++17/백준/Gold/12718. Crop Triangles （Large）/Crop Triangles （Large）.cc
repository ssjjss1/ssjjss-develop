#include <bits/stdc++.h>
using namespace std;

long long comb(long long n, int k) {
    if (n < k) return 0;
    if (k == 2) return n * (n - 1) / 2;
    if (k == 3) return n * (n - 1) * (n - 2) / 6;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        long long n, A, B, C, D, x, y, M;
        cin >> n >> A >> B >> C >> D >> x >> y >> M;

        long long cnt[3][3] = {0}; 
        cnt[x % 3][y % 3]+=1;

        for (int i = 1; i < n; i++) {
            x = (A * x + B) % M;
            y = (C * y + D) % M;
            cnt[x % 3][y % 3]+=1;
        }

        long long ans = 0;
        vector<pair<int, int>> al;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                al.push_back({i, j});

        for (int i = 0; i < 9; i++) {
            for (int j = i; j < 9; j++) {
                for (int k = j; k < 9; k++) {
                    long long x1 = al[i].first, y1 = al[i].second;
                    long long x2 = al[j].first, y2 = al[j].second;
                    long long x3 = al[k].first, y3 = al[k].second;
                    if ((x1 + x2 + x3) % 3 == 0 && (y1 + y2 + y3) % 3 == 0) {
                        if (i == j && j == k) {
                            ans += comb(cnt[x1][y1], 3);
                        } else if (i == j) {
                            ans += comb(cnt[x1][y1], 2) * cnt[x3][y3];
                        } else if (j == k) {
                            ans += comb(cnt[x2][y2], 2) * cnt[x1][y1];
                        } else if (i == k) {
                            ans += comb(cnt[x1][y1], 2) * cnt[x2][y2];
                        } else {
                            ans += cnt[x1][y1] * cnt[x2][y2] * cnt[x3][y3];
                        }
                    }
                }
            }
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }
}