#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> visited(1000004, 0);

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    visited[0] = visited[1] = 1;  
    for (int i = 2; i <= 1000000; i++) {
        if (!visited[i]) {
            for (int j = i * 2; j <= 1000000; j += i) { 
                visited[j] = 1;
            }
        }
    }

    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int cnt = 0;

        for (int i = 2; i <= x / 2; i++) {
            if (!visited[i] && !visited[x - i]) {
                cnt+=1;
            }
        }

        cout << cnt << "\n";
    }
}