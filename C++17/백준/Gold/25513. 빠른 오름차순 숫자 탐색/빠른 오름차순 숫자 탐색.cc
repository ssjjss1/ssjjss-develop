#include<bits/stdc++.h>
using namespace std;

const int dx[]= {1,0,-1,0}, dy[]= {0,1,0,-1};
int d[6][6];
int n,m;

int bfs(int x, int y, int target) {
	vector<vector<int>> visited(6, vector<int>(6,0));
	visited[x][y]=1;
	queue<tuple<int,int,int>> q;
	q.push({x,y,0});

	while(!q.empty()) {
		auto [cx, cy, cnt]=q.front();
		q.pop();

		if(d[cx][cy]==target) return cnt;

		for(int i=0; i<4; i++) {
			int nx=cx+dx[i], ny=cy+dy[i];
			if(nx<0||ny<0||nx>=5||ny>=5||visited[nx][ny]||d[nx][ny]==-1) continue;

			visited[nx][ny]=1;
			q.push({nx,ny,cnt+1});
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			cin>>d[i][j];
		}
	}

	cin>>n>>m;

	int ans=0;
	for(int i=1; i<=6; i++) {
		int cnt=bfs(n,m,i);
		if(cnt==-1) {
			cout<<-1;
			return 0;
		}
		ans+=cnt;
		for(int x=0; x<5; x++) {
			for(int y=0; y<5; y++) {
				if(d[x][y]==i) {
					n=x;
					m=y;
				}
			}
		}
	}

	cout<<ans;
}