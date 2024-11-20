#include <bits/stdc++.h>
using namespace std;
bool flag = true;
string s, result;
int Alpha[26];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    for (auto i : s)  Alpha[i - 'A']+=1;
    int oddcnt = 0;
    char oddChar = 0;
    for (int i = 0; i < 26; i++) {
        if (Alpha[i] % 2 == 1) {
            oddcnt+=1;
            oddChar = 'A' + i;
        }
        if (oddcnt > 1) { 
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    for (int i = 0; i < 26; i++) result += string(Alpha[i] / 2, 'A' + i);
    string rev = result;
    if(oddcnt==1)result += oddChar;
    reverse(rev.begin(), rev.end());
    result += rev; 
    cout << result;
}