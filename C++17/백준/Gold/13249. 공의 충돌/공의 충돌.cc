#include<bits/stdc++.h>
using namespace std;
int n,t;
vector<int> v;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++){
            int x; 
            cin>>x;
            v.push_back(x);
      }
      
      sort(v.begin(),v.end());
      
      cin>>t;
      
      int cnt=0;
      for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                  if(v[j]-v[i]<=2*t) cnt+=1;
            }
      }
      cout<<fixed<<setprecision(12)<<(double)cnt/4.0;
}