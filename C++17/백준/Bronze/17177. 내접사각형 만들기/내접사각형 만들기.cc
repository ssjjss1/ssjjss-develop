#include<iostream>
#include<cmath>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    if((sqrt((a*a-b*b)*(a*a-c*c))-b*c)/a<=0) cout<<-1;
    else cout<<(sqrt((a*a-b*b)*(a*a-c*c))-b*c)/a;
}