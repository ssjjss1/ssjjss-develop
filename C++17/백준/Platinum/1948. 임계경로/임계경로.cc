#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, a, b;
int d[10004], in[10004];
int dp[10004][10004];
vector<pair<int, int>> v[10004];
vector<int> v1[10004]; 
void f() {
    queue<int> q;
    q.push(a);
    d[a] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : v[x]) {
            int xx = i.first, cost = i.second;
            if (d[xx] < d[x] + cost) {
                d[xx] = d[x] + cost;
            }
            if (--in[xx] == 0) q.push(xx);
        }
    }
}
int g() {
    queue<int> q;
    q.push(b);
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : v1[x]) {
            for(auto j:v[i]){
              if((j.first==x)&&(d[x]==d[i]+j.second)&!dp[i][j.first]){
                cnt+=1;
                dp[i][j.first]=1;
                q.push(i);
              }
           }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        v[x].push_back({ y, z });
        v1[y].push_back(x);
        in[y]+=1;
    }
    cin >> a >> b;
    f();
    cout << d[b] << "\n";
    cout << g(); 
}