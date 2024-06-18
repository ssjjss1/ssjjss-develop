#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<int> v;
vector<int> visited;
vector<int> finished;
int cnt;

void dfs(int start) {
    int current = start;
    vector<int> stack;
    while (true) {
        stack.push_back(current);
        visited[current] = 1;
        int next = v[current];

        if (visited[next]) {
            if (!finished[next]) {
                // 사이클을 찾았을 때 사이클 길이를 카운트
                while (!stack.empty()) {
                    int top = stack.back();
                    stack.pop_back();
                    cnt++;
                    finished[top] = 1;
                    if (top == next) break;
                }
            }
            break;
        }

        current = next;
    }

    while (!stack.empty()) {
        int top = stack.back();
        stack.pop_back();
        finished[top] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n + 1);
        visited.assign(n + 1, 0);
        finished.assign(n + 1, 0);
        cnt = 0;

        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << n - cnt << "\n";
    }
    return 0;
}
