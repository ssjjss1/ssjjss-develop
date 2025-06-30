#include<bits/stdc++.h>
using namespace std;
const int INF=10000000;
bool visited[INF+4];
vector<int> primes;

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      for(int i=2;i<=INF;i++){
            if(!visited[i]){
                  primes.push_back(i);
                  for(int j=2*i;j<=INF;j+=i){
                        visited[j]=1;
                  }
            }
      }
      
      int n,m;
      string line;
      while (getline(cin, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            ss >> n >> m;
            int l=lower_bound(primes.begin(), primes.end(), n)-primes.begin();
            int r=upper_bound(primes.begin(), primes.end(), m)-primes.begin();
            cout<<r-l<<"\n\n";
      }
}