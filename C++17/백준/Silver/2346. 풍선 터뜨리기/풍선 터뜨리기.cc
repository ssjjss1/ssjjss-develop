#include<bits/stdc++.h>
using namespace std;
int n;
deque<pair<int, int>> dq;
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      cin>>n;
      for(int i=1; i<=n; i++){
            int x;
            cin>>x;
            dq.push_back({x, i});
      }
      
      while(!dq.empty()){
            cout << dq.front().second << " ";
            int x = dq.front().first;
            dq.pop_front();
            
            if(dq.empty()) break;
            
            if(x > 0){
                  for(int i=1; i<x; i++){
                        dq.push_back(dq.front());
                        dq.pop_front();
                  }
            } else {
                  for(int i=1; i<=-x; i++){
                        dq.push_front(dq.back());
                        dq.pop_back();
                  }
            }
      }
}