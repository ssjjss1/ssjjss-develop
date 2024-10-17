#include<bits/stdc++.h>
using namespace std;
long long reverse(string s){
      long long sum=0;
      for(int i=0;i<s.size();i++) sum+=(s[i]-'0')*pow(10,i);
      return sum;
}
int n;
vector<long long> v;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            v.push_back(reverse(s));
      } 
      sort(v.begin(),v.end());
      for(auto i:v) cout<<i<<"\n";
}