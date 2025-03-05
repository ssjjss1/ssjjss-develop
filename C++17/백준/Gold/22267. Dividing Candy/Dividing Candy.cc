#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n;
      if(n==1) {
            cout<<"N";
            return 0;
      }
      if(n==2){
            cout<<"Y";
            return 0;
      }
      priority_queue<int, vector<int>, greater<int>> pq;
      for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            pq.push(x);
      }
      
      vector<int> ans;
      while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            if(pq.empty()) {
                  ans.push_back(x);
                  break;
            }
            int y=pq.top();
            pq.pop();
            
            if(x==y){
                  pq.push(x+1);
            } else{
                  ans.push_back(x);
                  pq.push(y);
            }
      }
      
      if(ans.size()<=2) cout<<"Y";
      else cout<<"N";
}