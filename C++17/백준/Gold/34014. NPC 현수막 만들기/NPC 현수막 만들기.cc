#include<bits/stdc++.h>
using namespace std;
long long n,mn,mx;
string s;

long long comb(long long pl, long long l, long long r, long long nr){
    //if(pl > l) return 0;

    long long res = 0;
    long long nnr = nr - r - 1;
    long long len = r - l + 1;

    for(long long i = 0; i <= l - pl; i++){
        if(i + len + nnr < mn) continue;

        if(i + len > mx) break;
        else if(i + len >= mn) res += (nnr + 1) - max(0LL, i + len + nnr - mx);
        else if(i + len < mn){
            long long temp1 = max(0LL, mn - (i + len));
            long long temp2 = max(0LL, i + len + nnr - mx);
            res += (nnr + 1) - (temp1 + temp2);
        }
    }

    return res;
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n>>mn>>mx>>s;
      
      long long l=0,r=0, pl=0, nr=0;
      
      long long ans=0;
      while(true){
            while(l<n && s[l]!='N') {
                  if(s[l]=='C') pl=l;
                  l+=1;
            }
            
            if(l >= n - 1) break;
            r = l + 1;
            
            while(r<n && s[r]!='C' && s[r]!='N') {
                  r+=1;
            }
            
            if(s[r]=='C'&&s[(l+r)/2]=='P'&&!((l+r)%2)){
                  nr=r+1;
                  while(nr<n && s[nr]!='N' && s[nr]!='C'){
                        nr+=1;
                  }
                  
                  //cout<<pl<<" "<<l<<" "<<r<<" "<<nr<<"\n"; 
                  if((s[pl]=='N'||s[pl]=='C')&&pl!=l) pl+=1;
                  if(nr-pl>=mn) ans+=comb(pl,l,r,nr);
                  pl=r;
                  l=nr;
            } else {
                  pl=l;
                  l=r;
            }
            
            if(r >= n - 1) break;
      }
      
      cout<<ans;
}