#include<bits/stdc++.h>
#define INF 200004
using namespace std;

long long tree[INF * 4], lazy[INF * 4], compress[INF], compressTree[INF * 4];

long long compressCord(long long node, long long l, long long r) {
    if (l == r) {
        return compressTree[node] = compress[l];
    }
    int middle = (l + r) / 2;
    return compressTree[node] = (compressCord(node * 2, l, middle)
        + compressCord(node * 2 + 1, middle + 1, r));
}

void propagation(long long node, long long l, long long r) {
    if (lazy[node]) {
        tree[node] += lazy[node] * compressTree[node];
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

long long query(int node, long long l, long long r, long long x, long long y) {
    propagation(node, l, r);
    if (r < x || y < l) return 0;
    if (x <= l && r <= y) return tree[node];
    int middle = (l + r) / 2;
    return (query(node * 2, l, middle, x, y)
        + query(node * 2 + 1, middle + 1, r, x, y));
}

void update(long long node, long long l, long long r, long long x, long long y, long long val) {
    propagation(node, l, r);
    if (r < x || y < l) return;
    if (x <= l && r <= y) {
        lazy[node] += val;
        propagation(node, l, r);
        return;
    }
    int middle = (l + r) / 2;
    update(node * 2, l, middle, x, y, val);
    update(node * 2 + 1, middle + 1, r, x, y, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    int idx = 0;
    vector<int> coordList;
    vector<tuple<int, int, long long>> query1;
    vector<tuple<long long, int, int, int>> query2;

    for (int i = 1; i <= n; i++) {
        int mode, x, y;
        long long val;
        cin >> mode >> x >> y >> val;

        if (mode == 1) {
            query1.push_back({ x, y, val });
        }
        else {
            query2.push_back({ val, x, y, ++idx });
        }

        coordList.push_back(x);
        coordList.push_back(y);
    }

    sort(coordList.begin(), coordList.end());
    coordList.erase(unique(coordList.begin(), coordList.end()), coordList.end());

    map<int, int> coordMap;
    int m = coordList.size();
    for (int i = 0; i < m; i++) {
        coordMap[coordList[i]] = i * 2 + 1;
        if (i > 0) {
            compress[i * 2] = coordList[i] - coordList[i - 1] - 1;
        }
        compress[i * 2 + 1] = 1;
    }

    int maxIndex = m * 2;
    compressCord(1, 1, maxIndex);

    sort(query2.begin(), query2.end());

    vector<long long> res(idx + 4, -1);
    int j = 0;

    for (int i = 0; i < query1.size(); i++) {
        int x = get<0>(query1[i]);
        int y = get<1>(query1[i]);
        long long val = get<2>(query1[i]);

        x = coordMap[x];
        y = coordMap[y];

        update(1, 1, maxIndex, x, y, val);

        while (j < query2.size() && get<0>(query2[j]) == i + 1) {
            int nx = get<1>(query2[j]);
            int ny = get<2>(query2[j]);
            int id = get<3>(query2[j]);

            nx = coordMap[nx];
            ny = coordMap[ny];

            res[id] = query(1, 1, maxIndex, nx, ny);
            j += 1;
        }
    }

    for (int i = 1; i <= idx; i++) if (res[i] != -1) cout << res[i] << "\n";
}