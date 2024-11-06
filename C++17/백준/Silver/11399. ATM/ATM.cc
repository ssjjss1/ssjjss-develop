#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,ans1, ans2;
vector<int> v;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1,x;i<=n;i++) cin>>x,v.push_back(x);
      sort(v.begin(),v.end());
      for(auto i:v) ans1+=i, ans2+=ans1;
      cout<<ans2;
}