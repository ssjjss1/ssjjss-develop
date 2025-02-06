#include<bits/stdc++.h>
using namespace std;

int n, ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    set<string> s;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        if(str == "ENTER"){
            ans += s.size();
            s.clear();
        }
        else{
            s.insert(str);
        }
    }
    ans += s.size();
    cout << ans;
}