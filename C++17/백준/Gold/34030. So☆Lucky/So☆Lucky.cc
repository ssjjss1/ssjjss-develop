#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9+7, MIN = -1e9-7;
vector<pair<int,int>> pa;

bool check(const vector<int> &v){
      int n=v.size();
      for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]) return false;
      }
      
      return true;
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      int n;
      cin>>n;
      vector<int> v(n);
      for(int i=0;i<n;i++){
            cin>>v[i];
      }
      
      vector<int> even, odd;
      for(int i=0;i<n;i++){
            if(v[i]%2) odd.push_back(v[i]);
            else even.push_back(v[i]);
      }
      
      cout<<(check(even)&&check(odd)?"So Lucky\n":"Unlucky\n");
      
      int idx=1, r=v[0]%2, mn=v[0], mx=v[0];
      while(idx<n){
            if(r!=v[idx]%2){
                  pa.push_back({mn, mx});
                  mn=MAX, mx=MIN;
                  r=v[idx]%2;
            }
            mn=min(mn, v[idx]);
            mx=max(mx, v[idx]);
            idx+=1;
      }
      pa.push_back({mn, mx});
      
      for(int i=0;i<pa.size()-1;i++){
            auto [x, mx]=pa[i];
            auto [mn, y]=pa[i+1];
            
            if(mx>mn){
                  cout<<"Unlucky\n";
                  return 0;
            }
      }
      
      cout<<"So Lucky\n";
}