#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {-1,-1,0,0}, dx[4] = {-1,0,-1,0};

int n,m,q;
vector<vector<int>> d;
vector<vector<array<int,4>>> imos;
vector<vector<bool>> p;
long long cnt;

bool check(int x,int y){
    bool ch[4]={};
    for(int i=0;i<4;i++){
        int cx=x+dy[i];
        int cy=y+dx[i];
        if(cx<1||cx>n||cy<1||cy>m) return false;
        int temp=d[cx][cy]^imos[cx][cy][i];
        if(ch[temp]) return false;
        ch[temp]=true;
    }
    return true;
}

void go(int x,int y,int z,int t){
    int nx=x+dy[z];
    int ny=y+dx[z];
    if(nx<0||ny<0||nx>n+1||ny>m+1) return;
    imos[nx][ny][z]^=t;
}

vector<pair<int,int>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>q;
    d.assign(n+4,vector<int>(m+4,-1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;cin>>c;
            if(c=='E') d[i][j]=0;
            else if(c=='F') d[i][j]=1;
            else if(c=='W') d[i][j]=2;
            else d[i][j]=3;
        }
    }

    imos.assign(n+2,vector<array<int,4>>(m+2,{0,0,0,0}));
    p.assign(n+2,vector<bool>(m+2,false));

    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            p[i][j]=check(i,j);
            cnt+=p[i][j];
        }
    }
    cout<<cnt<<"\n";

    while(q--){
        int t,r1,c1,r2,c2;
        cin>>t>>r1>>c1>>r2>>c2;
        t&=3;
        v.clear();
        for(int i=c1;i<=c2+1;i++){
            v.emplace_back(r1,i);
            v.emplace_back(r2+1,i);
        }
        for(int i=r1+1;i<=r2;i++){
            v.emplace_back(i,c1);
            v.emplace_back(i,c2+1);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        
        for(auto &[x,y]:v) {
            cnt-=p[x][y];
        }
        for(int i=c1+1;i<=c2;i++){
            go(r1,i,2,t);
            go(r1,i,3,t);
        }
        go(r1,c1,3,t);
        go(r1,c2+1,2,t);
        for(int i=c1+1;i<=c2;i++){
            go(r2+1,i,0,t);
            go(r2+1,i,1,t);
        }
        go(r2+1,c1,1,t);
        go(r2+1,c2+1,0,t);
        for(int i=r1+1;i<=r2;i++){
            go(i,c1,1,t);
            go(i,c1,3,t);
        }
        for(int i=r1+1;i<=r2;i++){
            go(i,c2+1,0,t);
            go(i,c2+1,2,t);
        }
        for(auto &[x,y]:v){
            p[x][y]=check(x,y);
            cnt+=p[x][y];
        }
        cout<<cnt<<"\n";
    }
}