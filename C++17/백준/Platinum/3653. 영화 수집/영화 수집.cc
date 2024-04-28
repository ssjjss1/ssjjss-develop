#include <iostream>
#include <map>
#include <vector>
using namespace std;
int t, n, m, x;
map<int, int> a;
int g(vector<int> &tree, int i) {
  int ans = 0;
  while (i) {
    ans += tree[i];
    i -= (i & -i);
  }
  return ans;
}
void f(vector<int> &tree, int i, int j) {
  while (i <= tree.size()) {
    tree[i] += j;
    i += (i & -i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    vector<int> tree(200004);
    fill(&tree[0], &tree[0] + 200003, 0);
    a.clear();
    cin >> n >> m;
    int cnt = 100001;
    for (int i = 1; i <= n; i++) {
      f(tree, i + cnt, 1);
      a[i] = i + cnt;
    }
    while (m--) {
      cin >> x;
      int p = a[x];
      cout << g(tree, p) - 1 << " ";
      f(tree, p, -1);
      cnt-=1;
      f(tree, cnt, 1);
      a[x] = cnt;
    }
    cout << "\n";
  }
}