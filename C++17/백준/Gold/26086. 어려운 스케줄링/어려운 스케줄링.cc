#include <bits/stdc++.h>
using namespace std;

class Solve {
public:
    int n, q, k;
    vector<pair<int, int>> v;

    Solve() {
        cin >> n >> q >> k;
        v.resize(q);
        for (int i = 0; i < q; i++) {
            cin >> v[i].first;
            if (v[i].first == 0) {
                cin >> v[i].second;
            }
        }
    }

    void Answer() {
        int idx = -1;
        for (int i = 0; i < q; i++) {
            if (v[i].first == 1) idx = i;
        }

        bool flag = 0;
        for (int i = 0; i < idx; i++) {
            if (v[i].first == 2) flag = !flag;
        }

        deque<int> dq;
        for (int i = 0; i < idx; i++) {
            if (v[i].first == 0) dq.push_back(v[i].second);
        }
        if (idx != -1) {
            sort(dq.begin(), dq.end());
            flag = false;
        }

        for (int i = idx + 1; i < q; i++) {
            if (v[i].first == 0) {
                if (!flag) {
                    dq.push_front(v[i].second);
                } else {
                    dq.push_back(v[i].second);
                }
            } else if (v[i].first == 2) {
                flag = !flag;
            }
        }

        if (!flag) {
            cout << dq[k - 1] << '\n';
        } else {
            cout << dq[dq.size() - k] << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Solve problem;
    problem.Answer();
}