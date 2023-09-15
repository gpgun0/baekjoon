#include <bits/stdc++.h>

using namespace std;

bool compare(const std::vector<int>& a, const std::vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    }
    
    return a[1] > b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), compare);
    
    int prev_end = -1;
    for (auto target: targets) {
        int s = target[0], e = target[1];
        
        if (s < prev_end) {
            if (e < prev_end) {
                prev_end = e;
            }
        } else if (s >= prev_end) {
            prev_end = e;
            answer++;
        }
    }
    return answer;
}