#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) {
    vector<int> arr(n, 1);
    int answer = 0;
    
    for (int s: section) {
        arr[s-1] = 0;
    }
    
    for (int i=0; i<arr.size(); i++) {
        if (arr[i] == 0) {
            int to = min(i+m, (int)arr.size());
            for (int j=i; j<to; j++) {
                arr[j] = 1;
            }
            answer++;
        }
    }
    return answer;
}