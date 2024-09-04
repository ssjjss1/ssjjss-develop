#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, ans = -1e9;
vector<char> sign;
vector<int> num;
int g(int x, char c, int y) {
    if (c == '+') return x + y;
    if (c == '-') return x - y;
    if (c == '*') return x * y;
    return 0;
}
int h(vector<string> v) {
    vector<int> tnum;
    vector<char> tsign;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "*") {
            int p = tnum.back();
            tnum.pop_back();
            tnum.push_back(g(p, '*', stoi(v[i + 1])));
            i++;
        }
        else if (v[i] == "+" || v[i] == "-") tsign.push_back(v[i][0]);
        else tnum.push_back(stoi(v[i]));
    }
    int ans = tnum[0];
    for (int i = 0; i < tsign.size(); i++) ans = g(ans, tsign[i], tnum[i + 1]);
    return ans;
}
void f(int i, vector<string> v) {
    if (i == num.size()) {
        v.push_back(to_string(num[i - 1]));
        ans = max(ans, h(v));
        return;
    }
    vector<string> v1(v);
    if (i < num.size()) {
        v1.push_back(to_string(num[i]));
        if (i < sign.size()) v1.push_back(string(1, sign[i]));
        f(i + 1, v1);
    }
    if (i < sign.size()) {
        vector<string> v2(v);
        if (i + 1 < num.size()) {
            int k = g(num[i], sign[i], num[i + 1]);
            v2.push_back(to_string(k));
            if (i + 1 < sign.size()) v2.push_back(string(1, sign[i + 1]));
            f(i + 2, v2);
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (i % 2) num.push_back(c - '0');
        else sign.push_back(c);
    }
    vector<string> v;
    f(0, v);
    cout << ans;
}