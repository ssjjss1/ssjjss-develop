#include<bits/stdc++.h>
using namespace std;
int n;
int check(vector<int> v, int l){
      bool increasing=false, decreasing=false;
      int cnt=1;
      for(int i=l+1;i<n;i++){
            if(v[i]>v[i-1]){
                  if(increasing) break;
                  else cnt+=1, increasing=true;
                  decreasing=false;
            }
            else if(v[i]==v[i-1]) break;
            else{
                  if(decreasing) break;
                  else cnt+=1, decreasing=true;
                  increasing=false;
            }
      }
      return cnt;
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>n;
      vector<int> v;
      for(int i=1;i<=n;i++){
            int x; cin>>x;
            v.push_back(x);
      }
      int cnt=0;
      for(int i=0;i<n;i++){
           cnt+=check(v,i); 
      }
      cout<<cnt;
}