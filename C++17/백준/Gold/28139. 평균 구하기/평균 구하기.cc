#include<bits/stdc++.h>
using namespace std;
int n;
double ans;

vector<pair<int,int>> v;
int main(){
      ios_base::sync_with_stdio(0);cin.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
      }
      for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                  double dist=(v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second);
                  ans+=sqrt(dist);
            }
      }
      cout<<fixed<<setprecision(12)<<ans/n;
}