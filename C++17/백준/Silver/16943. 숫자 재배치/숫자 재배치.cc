#include<bits/stdc++.h>
using namespace std;
string a, c = "-1";
int b;
void f(string s, vector<int>& visited) {
    if (s.size() == a.size()) {
        if (s[0] != '0' && stoi(s) < b) {
            c = max(c, s); 
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (visited[i] > 0) {
            visited[i] -= 1;
            f(s + char(i + '0'), visited);
            visited[i] += 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    vector<int> visited(10, 0);
    for (char ch : a) visited[ch - '0'] += 1;
    f("", visited);
    cout << c;
}
