#include<iostream>
#include<vector>
using namespace std;
long long n,sum;
vector<int> v;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1,x;i<=n;i++) {
            cin>>x;
            if(x>0){
                  sum+=x;
                  v.push_back(i);
            }
      } 
      if(v.empty()) {
            cout<<n/2;
            return 0;
      }
      for(int i=0;i<v.size();i++){
            if(i==v.size()-1) sum+=((v[0]+n)-v[i])/2;
            else sum+=(v[i+1]-v[i])/2;
      }
      cout<<sum;
}