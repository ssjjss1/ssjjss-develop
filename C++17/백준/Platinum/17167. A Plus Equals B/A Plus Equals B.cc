#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll a,b;
vector<string> v;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>a>>b;
      while(true){
            if(a==1||b==1) break;
            if((a%2)&&(b%2)) {
                  if(a>b) v.push_back("A+=B"), v.push_back("B+=B"), a+=b, b+=b;
                  else v.push_back("B+=A"), v.push_back("A+=A"), b+=a, a+=a;
            }
            else if((a%2)) v.push_back("A+=A"),a+=a;
            else if((b%2)) v.push_back("B+=B"),b+=b;
            a/=2, b/=2;
      }
      if(a==b){
            cout<<v.size()<<"\n";
            for(auto i:v) cout<<i<<"\n";
            return 0;
      }
      else{
            while(true){
            if(a==1&&b==1) break;
            if(a==1){
                  if(b%2){
                        b+=1;
                        v.push_back("B+=A");
                        v.push_back("A+=A");
                        b/=2;
                  }
                  else{
                         v.push_back("A+=A");
                         b/=2;
                  }
            }
            else {
                  if(a%2){
                        a+=1;
                        v.push_back("A+=B");
                        v.push_back("B+=B");
                        a/=2;
                  }
                  else{
                         v.push_back("B+=B");
                         a/=2;
                  }
            }
      }
      }
      cout<<v.size()<<"\n";
      for(auto i:v) cout<<i<<"\n";
}