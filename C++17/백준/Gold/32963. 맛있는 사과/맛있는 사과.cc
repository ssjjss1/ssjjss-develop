#include<bits/stdc++.h>
using namespace std;
int n, q;
vector<long long> t, s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        long long x; cin >> x;
        t.push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        long long x; cin >> x;
        s.push_back(x);
    }

    vector<pair<int, int>> apples;
    for (int i = 0; i < n; i++) apples.push_back({t[i], s[i]});
    sort(apples.begin(), apples.end(), greater<>());

    vector<int> ans(q);
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        long long x; cin >> x;
        queries.push_back({x, i});
    }
    sort(queries.begin(), queries.end(), greater<>());

    long long j = 0, mx = 0, cnt = 0;
    for (int i = 0; i < q; i++) {
        int limit = queries[i].first, idx = queries[i].second;
        while (j < n && apples[j].first >= limit) {
            if(j==0) mx=apples[j].second, cnt=1;
            else{
                  if(mx<apples[j].second) mx=apples[j].second, cnt=1;
                  else if(mx==apples[j].second) cnt+=1;
            }
            j++;
        }
        ans[idx]=cnt;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}