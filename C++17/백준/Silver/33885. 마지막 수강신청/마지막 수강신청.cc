#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[6][24];
vector<int> sc;
vector<pair<string, int>> day[14];
map<string, int> week;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    week["MON"] = 1;
    week["TUE"] = 2;
    week["WED"] = 3;
    week["THU"] = 4;
    week["FRI"] = 5;

    cin >> n >> m;
    sc.resize(n);
    for (int i = 0; i < n; i++) {
        int c, s;
        cin >> c >> s;
        sc[i] = c;
        for (int j = 0; j < s; j++) {
            string s;
            int t;
            cin >> s >> t;
            day[i].push_back({s, t});
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        bool flag = false;
        memset(visited, 0, sizeof(visited));
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (auto [d, e] : day[j]) {
                    if (visited[week[d]][e]) {
                        flag = true;
                        break;
                    }
                    visited[week[d]][e] = 1;
                }
                if (flag) break;
                sum += sc[j];
            }
        }
        if (!flag && sum >= m) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}