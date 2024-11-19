#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
int p, q, r;
long long S;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    vector<int> score(N+4);
    for (int i = 0; i < N; i++) cin >> score[i];
    cin >> p >> q >> r >> S;
    int low = 1, high = 100001, K = INF;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += score[i];
            if (mid + r < score[i]) sum -= p;
            else if (score[i] < mid) sum += q;
        }
        if (sum < S) {
            low = mid + 1;
        } else {
            K = min(K, mid);
            high = mid - 1;
        }
    }
    cout << (K == INF ? -1 : K);
}