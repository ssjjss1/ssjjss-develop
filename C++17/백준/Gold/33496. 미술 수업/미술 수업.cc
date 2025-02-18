#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> diag1, diag2;
set<int> diag3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        
        if (count(diag1.begin(), diag1.end(), x-y) == 0) 
            diag1.push_back(x-y);
        if (count(diag2.begin(), diag2.end(), y + x) == 0) 
            diag2.push_back(y + x);
        
        diag3.insert(x-y);
        diag3.insert(y + x);
    }
    
    int sz = diag3.size(); 
    ans += sz;
    
    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());
    
    for (int i = 0; i < diag2.size(); i++) { 
        int x = diag2[i];
        auto it = lower_bound(diag1.begin(), diag1.end(), x);
        ans += distance(diag1.begin(),it);
    }
    
    cout << ans;
}