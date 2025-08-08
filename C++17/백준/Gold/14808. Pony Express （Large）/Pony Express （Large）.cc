#include <bits/stdc++.h>
using namespace std;

const double INF = 1e18;

struct H {
    long long E; 
    long long S;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        int n, q;
        cin >> n >> q;

        vector<H> ho(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ho[i].E >> ho[i].S;
        }

        vector<vector<long long>> dist(n + 4, vector<long long>(n + 4, INF));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                long long d;
                cin >> d;
                if (d != -1) dist[i][j] = d;
                if (i == j) dist[i][j] = 0; 
            }
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        vector<vector<double>> time(n + 4, vector<double>(n + 4, INF));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] <= ho[i].E) {
                    time[i][j] = (double)dist[i][j] / ho[i].S;
                }
            }
            time[i][i] = 0.0;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (time[i][k] + time[k][j] < time[i][j]) {
                        time[i][j] = time[i][k] + time[k][j];
                    }
                }
            }
        }

        cout << fixed << setprecision(9) << "Case #" << T << ":";
        while (q--) {
            int u, v;
            cin >> u >> v;
            cout << " " << time[u][v];
        }
        cout << "\n";
    }
}