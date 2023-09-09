#include <bits/stdc++.h>

using namespace std;

int t;
int k;
vector<int> dp(51, 0);

int isPossible(int target) {
    for (int i=1; i<51; i++) {
        for (int j=1; j<51; j++) {
            for (int k=1; k<51; k++) {
                if (dp[i] + dp[j] + dp[k] == target) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    cin >> t;

    for (int i=1; i<51; i++) {
        dp[i] = dp[i-1] + i;
    }

    while (t) {
        cin >> k;
        cout << isPossible(k) << "\n";
        t--;
    }

    return 0;
}