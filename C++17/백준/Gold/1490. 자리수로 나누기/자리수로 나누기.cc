#include <bits/stdc++.h>
using namespace std;
long long gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
long long lcm(int a, int b) {return a * b / gcd(a, b);}
int main() {
    string n; cin >> n;
    vector<int> v;
    for (auto c : n) {
        if (c != '0') v.push_back(c - '0');
    }
    long long Lcm = v[0];
    for (int i = 1; i < v.size(); i++) Lcm = lcm(Lcm, v[i]);
    long long num = stoi(n);
    long long Limit = 1;
    while (true) {
        long long t = num * Limit;
        for (long long i = 0; i < Limit; i++) {
            if (t % Lcm == 0) {
                cout << t;
                return 0;
            }
            t+=1;
        }
        Limit *= 10;
    }
}