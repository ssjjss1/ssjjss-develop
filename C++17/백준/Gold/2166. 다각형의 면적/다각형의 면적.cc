#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> P; 
int n;
vector<P> points;

double Ans(vector<P>& pts) {
    double area = 0;
    int n = pts.size();
    
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (pts[i].first * pts[j].second) - (pts[i].second * pts[j].first);
    }

    return abs(area) / 2.0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    points.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    cout << fixed << setprecision(1) << Ans(points);
}