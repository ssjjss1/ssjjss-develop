#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s1, s2;
    cin >> s1 >> s2;
    int cnt = 0, i = 0, n1 = s1.size(), n2 = s2.size();
    
    while (i < n2) {
        int mx = 0;
        for (int j = 1; j <= n2 - i; j++) {
            if (s1.find(s2.substr(i, j)) != string::npos) mx = j;
            else break;
        }
        i += mx;
        cnt+=1;
    }
    
    cout << cnt;
}