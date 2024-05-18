#include <iostream>
using namespace std;
int n, w, h, l;
int main() {
    cin >> n >> w >> h >> l;
    int ans = (w / l) * (h / l);
    cout << (n < ans ? n : ans);
}