#include<bits/stdc++.h>
#define P pair<char,int>
using namespace std;

int n;
vector<pair<char,int>> v;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n;
      
      for(int i=1;i<=n;i++){
            char c;
            int x;
            cin>>c>>x;
            v.push_back({c,x});
      }
      
      unordered_map<char, int> ma;
      ma['B']=1;
      ma['S']=2;
      ma['G']=3;
      ma['P']=4;
      ma['D']=5;
      
      vector<pair<char,int>> v1(v);
      
      sort(v.begin(),v.end(),[&](P &a, P &b){
            if(a.first==b.first) return a.second > b.second;
            return ma[a.first] < ma[b.first];
      });
      
      bool flag=true;
      vector<string> ans;
      for(int i=0;i<v.size();i++){
            if(v[i] != v1[i]){
                  flag=false;
                  string s1 = string(1, v[i].first) + to_string(v[i].second);
                  string s2 = string(1, v1[i].first) + to_string(v1[i].second);
                  ans.push_back(s1);
            }
      }
      
      if(flag){
            cout<<"OK";
      }else{
            cout<<"KO\n";
            for(auto s : ans) cout<<s<<" ";
      }
}