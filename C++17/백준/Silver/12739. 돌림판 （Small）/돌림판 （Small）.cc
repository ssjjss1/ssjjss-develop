#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
char P(char l, char cur, char r) {
    if ((l == cur && cur == r) || (l != cur && cur != r && l != r)) {
        return 'B';
    }
    else {
        map<char, int> ma;
        ma[l]+=1;
        ma[cur]+=1;
        ma[r]+=1;
        if (ma['R'] == 2 && ma['G'] == 1) return 'R';
        if (ma['G'] == 2 && ma['B'] == 1) return 'R';
        if (ma['B'] == 2 && ma['R'] == 1) return 'R';
        return 'G';
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> s;
    for (int i = 0; i < k; i++) {
        string nxt = s;
        for (int j = 0; j < n; j++) {
            nxt[j] = P(s[(j - 1 + n) % n], s[j], s[(j + 1) % n]);
        }
        s = nxt;
    }
    int red = count(s.begin(), s.end(), 'R');
    int green = count(s.begin(), s.end(), 'G');
    int blue = count(s.begin(), s.end(), 'B');
    cout << red << " " << green << " " << blue;
}