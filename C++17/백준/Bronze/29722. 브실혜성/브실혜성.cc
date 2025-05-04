#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>s>>n;
      
      int sum=stoi(s.substr(0,4))*360+(stoi(s.substr(5,2))-1)*30+(stoi(s.substr(8,2))-1);
      
      sum+=n;
      
      string year="0000", month="00", day="00";
      year+=to_string(sum/360);
      sum%=360;
      month+=to_string(sum/30 + 1);
      sum%=30;
      day+=to_string(sum + 1);
      
      cout<<year.substr(year.length()-4,4)+"-"+month.substr(month.length()-2,2)+"-"+day.substr(day.length()-2,2);
}