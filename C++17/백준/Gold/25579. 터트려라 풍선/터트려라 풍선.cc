#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> balloon(100004, 0), dart;
vector<bool> visited(100004, false);

int parent[100004], t_size[100004];
long long seg[100004];

void Init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        t_size[i] = 1;
        seg[i] = balloon[i];
    }
}

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y) {
        parent[x] = y;
        t_size[y] += t_size[x];
        seg[y] += seg[x];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> balloon[i];

    Init();

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        dart.emplace_back(x);
    }

    long long mx = 0, CurrentScore = 0;

    for (int i = dart.size() - 1; i >= 1; i--) {
        int idx = dart[i];
        visited[idx] = true;

        CurrentScore += balloon[idx];
        
        if(idx > 1 && visited[idx - 1]&&visited[idx+1]&&idx < n){
              CurrentScore-=balloon[idx];
              CurrentScore -= seg[Find(idx-1)] * t_size[Find(idx-1)];
              CurrentScore -= seg[Find(idx+1)] * t_size[Find(idx+1)];
              Union(idx-1, idx);
              Union(idx+1, idx);
              CurrentScore+=seg[Find(idx)]*t_size[Find(idx)];
        }
        else if (idx > 1 && visited[idx - 1]) {
            CurrentScore-=balloon[idx];
            CurrentScore -= seg[Find(idx-1)] * t_size[Find(idx-1)];
            Union(idx-1, idx);
            CurrentScore += seg[Find(idx)] * t_size[Find(idx)];
        }
        else if (idx < n && visited[idx + 1]) {
            CurrentScore-=balloon[idx];
            CurrentScore -= seg[Find(idx+1)] * t_size[Find(idx+1)];
            Union(idx+1, idx);
            CurrentScore += seg[Find(idx)] * t_size[Find(idx)];
        }
        
        mx = max(mx, CurrentScore);
    }

    cout << mx;
}