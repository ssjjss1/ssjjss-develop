#include <bits/stdc++.h>
using namespace std;

vector<string> a;
int l, n;
bool flag2 = false;

void backTracking(int cnt, vector<string> &ca, vector<bool> &visited) {
    if (flag2) return; 
    
    if (cnt == l) {
        for (int i = 0; i < l; i++) {
            string s = "";
            for (int j = 0; j < l; j++) s += ca[j][i];
            if (s != ca[i]) return;
        }
        for (int i = 0; i < l; i++) {
            cout << ca[i] << "\n";
        }
        flag2 = true;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        bool flag = true;
        for (int j = 0; j < cnt; j++) {
            if (ca[j][cnt] != a[i][j]) { 
                flag = false;
                break;
            }
        }
        if (!flag) continue;

        ca[cnt] = a[i];
        visited[i] = true;
        backTracking(cnt + 1, ca, visited);
        visited[i] = false;
        ca[cnt] = "";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end()); 

    vector<string> ca(l, "");
    vector<bool> visited(n, false);

    backTracking(0, ca, visited);

    if (!flag2) cout << "NONE\n";
}