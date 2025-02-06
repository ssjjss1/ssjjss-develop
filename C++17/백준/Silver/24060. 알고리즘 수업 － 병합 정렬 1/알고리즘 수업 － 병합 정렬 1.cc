#include<bits/stdc++.h>
using namespace std;
int n, m, cnt = 0, ans = -1;
vector<int> v, temp;

void merge(int x, int middle, int y) {
    int l = x, r = middle + 1, t = 0;
    while (l <= middle && r <= y) {
        if (v[l] <= v[r]) temp[t++] = v[l++];
        else temp[t++] = v[r++];
    }
    while (l <= middle) temp[t++] = v[l++];
    while (r <= y) temp[t++] = v[r++];
    for (l = x, t = 0; l <= y; l++, t++) {
        v[l] = temp[t];
        cnt++;
        if (cnt == m) ans = v[l];
    }
}

void Sort(int l, int r) {
    if (l < r) {
        int middle = (l + r) / 2;
        Sort(l, middle);
        Sort(middle + 1, r);
        merge(l, middle, r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    temp.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    Sort(0, n - 1);
    cout << ans;
}