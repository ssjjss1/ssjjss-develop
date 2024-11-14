#include<iostream>
using namespace std;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      int n;cin>>n;
      while(n--){
            string s,s1,s2;
            cin>>s;
            for(int i=0;i<s.size();i+=2) s1+=s[i];
            for(int i=1;i<s.size();i+=2) s2+=s[i];
            if(s.size()%2) cout<<s1<<s2<<"\n"<<s2<<s1<<"\n";
            else cout<<s1<<"\n"<<s2<<"\n";
      }
}