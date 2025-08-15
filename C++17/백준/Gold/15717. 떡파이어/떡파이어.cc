#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll mPow(ll b) {
    ll res = 1;
    ll a = 2;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    
    cout<<mPow(n-1);
}