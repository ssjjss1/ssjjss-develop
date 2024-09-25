#include<iostream>
#include<vector>
using namespace std;
long long n,k;
vector<int> v;
int visited[1000004];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>k;
      if((n-2)*(n-1)/2<k){
            cout<<-1;
            return 0;
      }
      for(int i=1;i<=n-2;i++) {
            if(k>=((n-1)-i)) k-=((n-1)-i),v.push_back(i),visited[i]=1;
            if(!k) break;
      }
      cout<<n<<" ";
      for(auto i:v) cout<<i<<" ";
      cout<<n-1<<" ";
      for(int i=n-2;i>=1;i--) if(!visited[i]) cout<<i<<" ";
}