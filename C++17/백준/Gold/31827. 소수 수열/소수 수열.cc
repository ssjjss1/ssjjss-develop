#include<bits/stdc++.h>
using namespace std;

int n, k;
bool visited[1000004];
vector<int> primes;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    for (int i = 3; i <= 1000000; i++) {
        if (!visited[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= 1000000; j += i) {
                visited[j] = 1;
            }
        }
    }
    
    vector<int> ans;
    if(k==8) k/=2;
    for (auto val : primes) {
        if (((val - 1) / 2) % k == 0) ans.push_back(val);
        if ((int)ans.size() == n) break;
    }
    
    for (auto i : ans) {
        cout << i << " ";
    }
}