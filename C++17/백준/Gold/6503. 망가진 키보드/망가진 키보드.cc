#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while (true) {
        int m; cin >> m;
        if (m == 0) return 0;
        cin.ignore();
        string s; 
        getline(cin, s);
        int l = 0, r = 0, ans = 0;
        unordered_map<char, int> freq;
        while (r < s.size()) {
            freq[s[r]]+=1;
            while (freq.size() > m) {
                freq[s[l]]-=1;
                if (freq[s[l]] == 0) freq.erase(s[l]);
                l+=1;
            }
            ans = max(ans, r - l + 1);
            r+=1;
        }
        cout << ans << "\n";
    }
}