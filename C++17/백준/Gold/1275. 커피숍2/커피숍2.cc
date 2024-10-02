#include<iostream>
using namespace std;
typedef long long ll;
ll n, m;
ll d[100004], t[400004];
void init(ll node, int l, int r){
      if(l == r){
            t[node] = d[l];
            return;
      }
      ll m = (l + r) / 2;
      init(node * 2, l, m);
      init(node * 2 + 1, m + 1, r);
      t[node] = t[node * 2] + t[node * 2 + 1];
}
void update(int x, ll diff, ll node, int l, int r){
      if(l == r){
            t[node] += diff;
            return;
      }
      ll m = (l + r) / 2;
      if(x <= m) update(x, diff, node * 2, l, m);
      else update(x, diff, node * 2 + 1, m + 1, r);
      t[node] = t[node * 2] + t[node * 2 + 1]; 
}
ll query(int x, int y, ll node, int l, int r){
      if(y < l || x > r) return 0; 
      if(x <= l && r <= y) return t[node];
      ll m = (l + r) / 2;
      return query(x, y, node * 2, l, m) + query(x, y, node * 2 + 1, m + 1, r);
}
int main(){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin >> n >> m;
      for(int i = 1; i <= n; i++) cin >> d[i];
      init(1, 1, n);
      while(m--){
            ll x, y, a, b;
            cin >> x >> y >> a >> b;
            if(x > y) swap(x, y); 
            cout << query(x, y, 1, 1, n) << "\n";
            update(a, b - d[a], 1, 1, n); 
            d[a] = b;
      }
}