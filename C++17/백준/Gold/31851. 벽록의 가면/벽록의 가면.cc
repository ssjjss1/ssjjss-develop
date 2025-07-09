#include <bits/stdc++.h>
#define Point pair<int,int>
using namespace std;

int ccw(Point a, Point b, Point c) {
    long long cross = 1LL*(b.first - a.first)*(c.second - a.second) - 1LL*(b.second - a.second)*(c.first - a.first);
    if (cross > 0) return 1;
    if (cross < 0) return -1;
    return 0;
}

bool check(vector<Point> &pts) {
    int dir = ccw(pts[0], pts[1], pts[2]);
    for (int i = 1; i < 4; i++) {
        int d = ccw(pts[i], pts[(i+1)%4], pts[(i+2)%4]);
        if (d * dir <= 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Point> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                for(int l = k+1; l < n; l++) {
                    vector<int> idx = {i, j, k, l};
                    vector<Point> square(4);
                    do {
                        for (int m = 0; m < 4; m++) square[m] = v[idx[m]];
                        if (check(square)) {
                            cnt+=1;
                            break; 
                        }
                    } while (next_permutation(idx.begin(), idx.end()));
                }
            }
        }
    }

    cout << cnt;
}