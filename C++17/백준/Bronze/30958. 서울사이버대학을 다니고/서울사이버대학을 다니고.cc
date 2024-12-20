#include <bits/stdc++.h>
using namespace std;
map<char, int> ma;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    for (char c : s) if (isalpha(c)) ma[c]+=1;
    int mx = 0;
    for (auto [chr, cnt] : ma) mx = max(mx, cnt);
    cout << mx;
}