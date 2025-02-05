#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    stack<int> stk;
    int idx = 1; 
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x; 
        if (x == idx) {
            idx+=1;
        } else {
            stk.push(x);
        }

        while (!stk.empty() && stk.top() == idx) {
            stk.pop();
            idx+=1;
        }
    }

    if (stk.empty()) cout << "Nice";
    else cout << "Sad";
}