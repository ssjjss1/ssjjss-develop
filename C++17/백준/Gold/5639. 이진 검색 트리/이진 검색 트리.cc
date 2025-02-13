#include <bits/stdc++.h>
using namespace std;

vector<int> in;

void post_tree(int s, int e) {
    if (s >= e) return;
    int idx = s + 1;
    
    while (idx < e && in[idx] < in[s]) {
        idx++;
    }
    
    post_tree(s + 1, idx);
    post_tree(idx, e);
    cout << in[s] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int num;
    while (cin >> num) {
        in.push_back(num);
    }
    
    post_tree(0, in.size());
}