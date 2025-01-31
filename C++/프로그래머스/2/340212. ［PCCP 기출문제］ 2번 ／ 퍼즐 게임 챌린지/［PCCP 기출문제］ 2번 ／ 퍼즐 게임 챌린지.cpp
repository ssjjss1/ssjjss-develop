#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int l=1, r=100004;
    while(l<=r){
        int middle=(l+r)/2;
        long long sum=0;
        for(int i=0;i<diffs.size();i++){
            if(middle>=diffs[i]){
                sum+=times[i];
            }else{
                int t=diffs[i]-middle;
                sum+=(times[i]+times[i-1])*t+times[i];
            }
        }
        if(sum<=limit) answer=middle, r=middle-1;
        else l=middle+1;
    }
    
    return answer;
}