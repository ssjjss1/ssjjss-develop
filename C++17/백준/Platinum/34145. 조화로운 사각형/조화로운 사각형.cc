#include <bits/stdc++.h>
using namespace std;
typedef unsigned char uc;

const int dy[4] = {-1,-1,0,0}, dx[4] = {-1,0,-1,0};

int n,m,q;
vector<vector<uc>> d;
vector<vector<array<uc,4>>> imos;
vector<vector<uc>> p, visited;
long long cnt;

inline bool check(int x,int y){
    int l = 0;
    for(int i=0;i<4;i++){
        int cx = x + dy[i];
        int cy = y + dx[i];
        if(cx < 1 || cx > n || cy < 1 || cy > m) return false;
        int temp = d[cx][cy] ^ imos[cx][cy][i];
        int ma = 1<<temp;
        if(l & ma) return false;
        l |= ma;
    }
    return true;
}

inline void go(int x,int y,int z,int t){
    int nx = x + dy[z];
    int ny = y + dx[z];
    if(nx < 0 || ny < 0 || nx > n+1 || ny > m+1) return;
    imos[nx][ny][z] ^= (uc)t;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    d.assign(n+4, vector<uc>(m+4, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c; 
            cin >> c;
            if(c=='E') d[i][j] = 0;
            else if(c=='F') d[i][j] = 1;
            else if(c=='W') d[i][j] = 2;
            else d[i][j] = 3;
        }
    }

    imos.assign(n+4, vector<array<uc, 4>>(m+4));
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            imos[i][j] = {0,0,0,0};
        }
    }

    p.assign(n+2, vector<unsigned char>(m+2, 0));
    visited.assign(n+2, vector<unsigned char>(m+2, 0));

    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            p[i][j]=check(i,j);
            cnt+=p[i][j];
        }
    }
    cout << cnt << "\n";

    vector<pair<int,int>> v;

    while(q--){
        int t, r1, c1, r2, c2;
        cin >> t >> r1 >> c1 >> r2 >> c2;
        t &= 3;

        v.clear();

        for(int i=c1;i<=c2+1;i++){
            if(!visited[r1][i]){ 
                visited[r1][i]=1; 
                v.emplace_back(r1,i); 
            }
            if(!visited[r2+1][i]){ 
                visited[r2+1][i]=1; 
                v.emplace_back(r2+1,i); 
            }
        }
        for(int i=r1+1;i<=r2;i++){
            if(!visited[i][c1]){ 
                visited[i][c1]=1; 
                v.emplace_back(i,c1); 
            }
            if(!visited[i][c2+1]){ 
                visited[i][c2+1]=1; 
                v.emplace_back(i,c2+1); 
            }
        }

        for(auto &[x,y]:v){
            if(p[x][y]) {
                cnt -= 1;
            }
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
            p[x][y] = check(x,y);
            cnt += p[x][y];
            visited[x][y] = 0;
        }

        cout << cnt << "\n";
    }
}