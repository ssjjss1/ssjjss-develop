 #include<bits/stdc++.h>
#define INF 200004
using namespace std;

vector<bool> visited(INF);
vector<int> a(INF);
int n;

int dfs(int x){
    if(visited[x]) return 0;
    visited[x]=1;
    return 1+dfs(a[x]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int cnt1=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=i&&!visited[a[i]]){
            cnt1+=dfs(a[i])-1;
        }
    }

    int cnt2=0;
    fill(visited.begin(), visited.end(), 0);
    reverse(a.begin()+1, a.begin()+n+1);
    
    for(int i=1;i<=n;i++){
        if(a[i]!=i&&!visited[a[i]]){
            cnt2+=dfs(a[i])-1;
        }
    }

    cout<<n-2<<" "<<min(cnt1, cnt2);
}