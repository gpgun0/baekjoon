#include <bits/stdc++.h>

using namespace std;
map<char, int> char_min;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for (string key: keymap) {
        for (int i=0; i<key.length(); i++) {
            if (char_min.find(key[i]) != char_min.end()) {
                char_min[key[i]] = min(char_min[key[i]], i+1);
            } else {
                char_min[key[i]] = i+1;
            }
        }
    }
    
    for (auto target: targets) {
        int sum = 0;
        for (auto c: target) {
            if (char_min.find(c) == char_min.end()) {
                answer.push_back(-1);
                sum = 0;
                break;
            }
            sum += char_min[c];
        }
        
        if (sum != 0) {
            answer.push_back(sum);        
        }
    }
    return answer;
}