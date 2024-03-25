#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long int ll;
unordered_map<ll, ll> v;
ll n,p,q; 
ll f(ll x) {
    if (v.find(x) != v.end()) return v[x];
    v[x] = f(x / p) + f(x / q);
    return v[x];
}
int main(){
    v[0] = 1;
    cin >> n >> p >> q;
    cout << f(n);
}