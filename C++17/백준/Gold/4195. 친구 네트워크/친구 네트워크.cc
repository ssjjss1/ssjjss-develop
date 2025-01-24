#include<bits/stdc++.h>
using namespace std;

unordered_map<string, string> name;
unordered_map<string, int> num;

string find(string s) {
    if (name[s] == s) return s;
    return name[s] = find(name[s]);
}

void union_sets(string x, string y) {
    x = find(x), y = find(y);
    if (x != y) {
        name[x] = y;
        num[y] += num[x];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        name.clear();
        num.clear();
        for (int i = 1; i <= n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (name.find(s1) == name.end()) {
                name[s1] = s1;
                num[s1] = 1;
            }
            if (name.find(s2) == name.end()) {
                name[s2] = s2;
                num[s2] = 1;
            }
            union_sets(s1, s2);
            cout << num[find(s1)] << "\n";
        }
    }
}