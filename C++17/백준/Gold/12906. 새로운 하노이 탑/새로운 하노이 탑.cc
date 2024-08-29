#include<bits/stdc++.h>
using namespace std;
int n;
string A, B, C;
string sA, sB, sC;
void f(string s) {
    for (auto i : s) {
        if (i == 'A') sA += 'A';
        else if (i == 'B') sB += 'B';
        else sC += 'C';
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n > 0) cin >> A, f(A);
    cin >> n;
    if (n > 0) cin >> B, f(B);
    cin >> n;
    if (n > 0) cin >> C, f(C); 
    queue<pair<pair<string, string>, pair<string, int>>> q; 
    set<tuple<string, string, string>> visited; 
    q.push({ {A, B}, {C, 0} });  
    visited.insert(make_tuple(A, B, C));
    while (!q.empty()) {
        string x = q.front().first.first, y = q.front().first.second, z = q.front().second.first; 
        int cnt = q.front().second.second; 
        q.pop();
        if (x == sA && y == sB && z == sC) {
            cout << cnt << '\n';
            return 0;
        }
        if (!x.empty()) {
            string xx = x.substr(0, x.size() - 1);
            string yy = y + x.back();
            if (visited.find(make_tuple(xx, yy, z)) == visited.end()) {
                q.push({ {xx, yy}, {z, cnt + 1} });
                visited.insert(make_tuple(xx, yy, z));
            }
            string zz = z + x.back();
            if (visited.find(make_tuple(xx, y, zz)) == visited.end()) {
                q.push({ {xx, y}, {zz, cnt + 1} });
                visited.insert(make_tuple(xx, y, zz));
            }
        }
        if (!y.empty()) {
            string yy = y.substr(0, y.size() - 1);
            string xx = x + y.back();
            if (visited.find(make_tuple(xx, yy, z)) == visited.end()) {
                q.push({ {xx, yy}, {z, cnt + 1} });
                visited.insert(make_tuple(xx, yy, z));
            }
            string zz = z + y.back();
            if (visited.find(make_tuple(x, yy, zz)) == visited.end()) {
                q.push({ {x, yy}, {zz, cnt + 1} });
                visited.insert(make_tuple(x, yy, zz));
            }
        }
        if (!z.empty()) {
            string zz = z.substr(0, z.size() - 1);
            string xx = x + z.back();
            if (visited.find(make_tuple(xx, y, zz)) == visited.end()) {
                q.push({ {xx, y}, {zz, cnt + 1} });
                visited.insert(make_tuple(xx, y, zz));
            }
            string yy = y + z.back();
            if (visited.find(make_tuple(x, yy, zz)) == visited.end()) {
                q.push({ {x, yy}, {zz, cnt + 1} });
                visited.insert(make_tuple(x, yy, zz));
            }
        }
    }
}