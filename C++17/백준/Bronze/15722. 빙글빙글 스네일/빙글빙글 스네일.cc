#include<bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int x = 0, y = 0;

    int dir = 0, len = 1, cnt = 0; 

    for(int i = 1; i <= n;){
        for(int j = 0; j < len && i <= n; j++, i++){
            x += dx[dir];
            y += dy[dir];
        }
        dir = (dir + 1) % 4;
        cnt+=1;
        if(cnt % 2 == 0) len+=1;
    }

    cout << x << " " << y;
}