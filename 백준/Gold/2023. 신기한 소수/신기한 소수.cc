#include <bits/stdc++.h>
int n;

using namespace std;
bool check(int k) {
    if (k == 2) {
        return true;
    }

    if (k < 2) {
        return false;
    }

    for (int i=2; i<=sqrt(k); i++) {
        if (k%i == 0) {
            return false;
        }
    }

    return true;
}

void dfs(int num) {
    if (num != 0 && to_string(num).length() == n) {
        cout << num << "\n";
        return;
    }

    for (int i=1; i<10; i++) {
        if (check(num*10 + i)) {
            dfs(num*10 + i);
        }
    }

    return;
}

int main() {
    cin >> n;

    dfs(0);

    return 0;
}