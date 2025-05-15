#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 1, r = n;
    int cnt = 0;

    while (cnt < 20) {
        int middle = (l + r) / 2;
        cout << "? " << middle << endl;
        cout.flush();

        int x;
        cin >> x;

        if (middle == 2 * x) {
            cout << "! " << middle << endl;
            cout.flush();
            return 0;
        } else if (middle  > 2 * x) {
            r = middle - 1;
        } else {
            l = middle + 1;
        }
        cnt+=1;
    }
}