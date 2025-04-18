#include <bits/stdc++.h>
using namespace std;

vector<long long> v;
bool flag;

void init() {
    long long num = 8;
    while (num <= 1e18) {
        v.push_back(num);
        num = num * 10 + 8;
    }
    sort(v.begin(), v.end(), greater<>());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        flag = true;
        
        int cnt=0;
        
        for(auto i:v){
              cnt+=n/i;
              
              if(cnt>8) {
                    flag=false;
                    break;
              }
              
              n%=i;
        }
        
        if(n) flag=false;
        
        cout << (flag ? "Yes\n" : "No\n");
    }
}