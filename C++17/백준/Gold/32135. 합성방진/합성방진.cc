#include<bits/stdc++.h>
using namespace std;
int n;
bool visited[1004];
int visitedX[504], visitedY[504];

void check(int x){
      for(int i=2;i<=x;i++){
            if(!visited[i]){
                  for(int j=2*i;j<=x;j+=i){
                        visited[j]=1;
                  }
            }
      }
}

pair<int,int> find_mul(int x, int y){
      for(int i=x;i<=n;i+=2){
            for(int j=y;j<=n;j+=2){
                  if(visited[i+j]&&!visitedX[i]&&!visitedY[j]) {
                        visitedX[i]=1;
                        visitedY[j]=1;
                        return {i,j};
                  }
            }
      }
      return {-1,-1};
}

void run(){
      int x1=2, y1=1;
      int x2, y2;
      while(true){
            tie(x1, y1)=find_mul(x1, y1);
            
            if(x1==-1||x1+y1>=2*n-1) {
                  cout<<-1;
                  break;
            }
            
            tie(x2, y2)=find_mul(2, 1);
            
            if(x2==-1) {
                  visitedX[x1]=0;
                  visitedY[y1]=0;
                  continue;
            }
            
            vector<int> ans;
            ans.push_back(x1);
            for(int i=2;i<=n;i+=2){
                  if(x1!=i&&x2!=i) ans.push_back(i);
            }
            ans.push_back(x2);
            
            ans.push_back(y2);
            for(int i=1;i<=n;i+=2){
                  if(y1!=i&&y2!=i) ans.push_back(i);
            }
            ans.push_back(y1);
            
            for(int i=0;i<n;i++){
                  for(int j=i;j<i+n;j++){
                        cout<<ans[j%n]<<" ";
                  }
                  cout<<"\n";
            }
            break;
      }
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n;
      check(2*n);
      run();
}