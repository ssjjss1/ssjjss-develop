#include <bits/stdc++.h>
#define INF 3004
using namespace std;

vector<pair<int, long long>> sum(INF * INF, {0, 0});
map<long long, int> indexCheck;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        indexCheck[v[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            long long diff = v[i] - v[j];
            long long prev = v[j] - diff;

            long long K = j + INF * i;
            if (prev > 0 && indexCheck.count(prev)) {
                int k = indexCheck[prev];
                long long prevK = k + INF * j;
                sum[K] = {sum[prevK].first + 1, sum[prevK].second + v[i]};
            } else {
                sum[K] = {2, v[i] + v[j]};
            }
        }
    }

    long long ans = 0;
    for (auto &[cnt, s] : sum) {
        if (cnt > 2) {
            ans = max(ans, s);
        }
    }

    cout << ans;
}