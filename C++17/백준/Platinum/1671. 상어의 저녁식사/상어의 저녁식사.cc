#include<bits/stdc++.h>
#define INF 54
using namespace std;

int n;
vector<int> v[INF], B(INF * 2, -1), A(INF * 2, -1);
vector<bool> visited;

struct P {
    long long a, b, c;
};

bool dfs(int a) {
    visited[a] = true;
    for (auto b : v[a]) {
        if (B[b] == -1 || (!visited[B[b]] && dfs(B[b]))) {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

void bipartite_matching() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            visited.assign(INF * 2, false);
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<P> shark(n);
    for (int i = 0; i < n; i++) {
        cin >> shark[i].a >> shark[i].b >> shark[i].c;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if(shark[i].a == shark[j].a && shark[i].b == shark[j].b && shark[i].c == shark[j].c) {
                  if(i < j){
                        v[i].push_back(j + INF);
                  }
            }
            else if (shark[i].a >= shark[j].a && shark[i].b >= shark[j].b && shark[i].c >= shark[j].c) {
                v[i].push_back(j + INF);
            }
        }
    }
    
    bipartite_matching();
    
    int ans = 0;
    for (int i = INF; i < INF + n; i++) {
        if (B[i] == -1) ans+=1;
    }
    
    cout << ans;
}