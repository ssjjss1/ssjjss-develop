#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
      ios::sync_with_stdio(0); cin.tie(0);
      cin>>t;
      while(t--){
            int n; cin>>n;
            vector<int> v;
            int avg=0;
            for(int i=1;i<=n;i++){
                  double x; cin>>x;
                  v.push_back(x);
                  avg+=x;
            }
            int cnt=0;
            for(auto i:v){
                  if(avg<i*n) cnt+=1;
            }
            
            cout<<fixed<<setprecision(3)<<(double)cnt*100/(double)n<<"%\n";
      }
}