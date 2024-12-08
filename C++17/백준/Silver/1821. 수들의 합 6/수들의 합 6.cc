#include <bits/stdc++.h>
using namespace std;
int n, f;
vector<int> v, d, ans;     
void Combination() {
    v.resize(n);
    v[0] = v[n - 1] = 1;
    for (int i = 1; i < n - 1; i++) v[i] = v[i - 1] * (n - 1 - i + 1) / i;
}
int Sum(vector<int> seq) {
    vector<int> t(seq);
    int sum=0;
    for(int i=0;i<n;i++) sum+=v[i]*t[i];
    return sum;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> f;
    Combination();
    d.resize(n);
    iota(d.begin(), d.end(), 1); 
    do {
        if (Sum(d) == f) {
            ans = d;
            break;
        }
    } while (next_permutation(d.begin(), d.end()));
    for (auto i : ans) cout << i << " ";
}