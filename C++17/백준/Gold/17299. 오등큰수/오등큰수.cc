#include<bits/stdc++.h>
using namespace std;

stack<int> stk;
vector<int> v, freq, result;
int n;
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      
      cin >> n;
      v.resize(n+4);
      freq.resize(1000004, 0);
      result.resize(n+4, -1);

      for (int i = 0; i < n; i++) {
            cin >> v[i];
            freq[v[i]]+=1;
      }

      for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && freq[v[stk.top()]] <= freq[v[i]]) {
                  stk.pop();
            }
            if (!stk.empty()) result[i] = v[stk.top()];
            stk.push(i);
      }

      for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
      }
}