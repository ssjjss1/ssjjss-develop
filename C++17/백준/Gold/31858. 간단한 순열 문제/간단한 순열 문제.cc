#include <iostream>
#include <stack>
using namespace std;
int n;
stack<int> st;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int sum = n - 1;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    while (st.size() && st.top() < x) {
      if(st.size()!=1) sum+=1;
      st.pop();
    }
    st.push(x);
  }
  cout << sum;
}