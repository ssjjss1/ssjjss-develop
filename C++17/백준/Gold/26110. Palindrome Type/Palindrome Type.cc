#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1e9+4;
int mn=inf;
int check(string s) {
    for (int i = 0; i < s.size() / 2; i++) 
        if (s[i] != s[s.size() - i - 1]) 
            return i; 
    return -1; 
}
void f(string s, int cnt) {
    if (cnt > 3) return;
    int index = check(s);
    if (index == -1) { 
        mn = min(mn, cnt); 
        return;
    }
    f(s.substr(0, index) + s.substr(index + 1), cnt + 1);
    f(s.substr(0, s.size() - index - 1) + s.substr(s.size() - index), cnt + 1); 
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    if (check(s) == -1) { 
        cout << 0;
        return 0;
    }
    f(s, 0);
    if (mn == inf) cout << -1;
    else cout << mn;
}