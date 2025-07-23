#include<bits/stdc++.h>
#define INF 504
using namespace std;

const int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};

struct P{
    int x,y;
};

int n,m,k;
int d[INF][INF];
bool visited[INF][INF];
P ab[5];

long long bfs(int x, int y){
    queue<P> q;
    q.push({x,y});
    visited[x][y]=1;
    long long res1=0, res2=0;
    if(ab[1].x<=x&&ab[1].y<=y&&ab[2].x>=x&&ab[2].y>=y) res1+=1;
    if(ab[3].x<=x&&ab[3].y<=y&&ab[4].x>=x&&ab[4].y>=y) res2+=1;

    while(!q.empty()){
        auto [cx, cy]=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nx=cx+dx[i], ny=cy+dy[i];

            if(nx<1||ny<1||nx>n||ny>m||visited[nx][ny]||d[nx][ny]==-1) continue;

            if(ab[1].x<=nx&&ab[1].y<=ny&&ab[2].x>=nx&&ab[2].y>=ny) res1+=1;
            if(ab[3].x<=nx&&ab[3].y<=ny&&ab[4].x>=nx&&ab[4].y>=ny) res2+=1;
            q.push({nx, ny});
            visited[nx][ny]=1;
        }
    }

    //cout<<res1<<" "<<res2<<"\n";
    return res1*res2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        d[x][y]=-1;
    }

    for(int i=1;i<=4;i++){
        cin>>ab[i].x>>ab[i].y;
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!visited[i][j]&&d[i][j]!=-1){
                ans+=bfs(i, j);
            }
        }
    }

    cout<<ans;
}