#include<iostream>
using namespace std;
string s1[] = {
        "", 
        "one", "two", "three", "four", "five", 
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
        "twenty one", "twenty two", "twenty three", "twenty four", "twenty five",
        "twenty six", "twenty seven", "twenty eight", "twenty nine",
        "",
    };
void f(int n, int m, string s){
      if(m==0) cout<<s1[n]+" o' clock";
      else if(m==1) cout<<s1[m]+" minute "+ s +" "+s1[n];
      else if(m==15) cout<<"quarter "+s+" "+s1[n];
      else if(m>=2&&m<=29) cout<<s1[m]+" minutes "+s+" "+s1[n];
      else if(m==30) cout<<"half past "+s1[n];
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      int n,m;
      cin>>n>>m;
      if(m<=30) f(n, m, "past");
      else f((n==12?1:n+1),60-m,"to");
}