#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        int x;
        cin >> x;

        if(x == 0) break;

        int t0 = 0, t1 = 1;
        int p = 0;

        do {
            int next = (t0 + t1) % x;
            t0 = t1;
            t1 = next;
            p+=1;
        } while (!(t0 == 0 && t1 == 1));

        cout << x << " " << p << "\n";
    }
}