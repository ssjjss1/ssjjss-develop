#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int find_zero(string s) {
    int k = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            k += 1;
        }
    }
    return k;
}

string change(int num) {
    string s = "";
    int idx;
    for (int i = 0; i <= 30; i++) {
        if (num < (1 << i)) {
            idx = i - 1;
            break;
        }
    }
    for (int i = idx; i >= 0; i--) {
        if ((1 << i) <= num) {
            s += '1';
            num -= (1 << i);
        } else {
            s += '0';
        }
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int level = 0, sum1 = 0, sum2 = 0;
    
    while (s != "1") {
        level += 1;
        
        int zero_count = find_zero(s);
        int non_zero = s.size() - zero_count;
        
        sum1 += non_zero;
        sum2 += zero_count;
        
        if(non_zero==1) break; 
        
        s = change(non_zero);
        
    }
    
    answer.emplace_back(level);
    answer.emplace_back(sum2);
    
    return answer;
}