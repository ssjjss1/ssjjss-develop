#include<bits/stdc++.h>
using namespace std;
int n,m;
string num[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>n>>m;
      vector<pair<string, int>> v;
      for(int i=n;i<=m;i++){
            int t1=i/10, t2=i%10;
            string s="";
            if(t1) s+=num[t1];
            s+=num[t2];
            v.push_back({s,i});
      }
      sort(v.begin(),v.end());
      for(int i=0;i<v.size();i++){
            cout<<v[i].second<<" ";
            if(i%10==9) cout<<"\n";
      }
}