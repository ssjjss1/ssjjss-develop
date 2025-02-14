#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int sum2[500004];

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n;
      for(int i=0;i<n;i++) {
            int x; 
            cin>>x;
            v.push_back(x);
      }
      sort(v.begin(),v.end());
      
      vector<int> left(n+4, 0), right(n+4, 0);
      for(int i = 1; i < n; i += 2) {
            left[i] = (v[i] - v[i-1]);
            if (i - 2 >= 0) left[i] += left[i-2];
      }
      
      for(int i = n - 2; i > 0; i -= 2) {
            right[i] = (v[i+1] - v[i]);
            if (i + 2 < n) right[i] += right[i+2];
      }
      
      int ans = 1e9+7;
      for(int i = 0; i < n - 2; i += 2) {
            int t = (v[i+2] - v[i]);
            if (i - 1 >= 0) t += left[i-1];
            if (i + 3 < n) t += right[i+3];
            ans = min(ans, t);
      }
      
      cout << ans;
}