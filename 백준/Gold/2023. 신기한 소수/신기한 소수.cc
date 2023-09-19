#include <bits/stdc++.h>
int n;

using namespace std;
bool check(int k) {
    if (k < 2) {
        return false;
    }

    for (int i=2; i<sqrt(k)+1; i++) {
        if (k%i == 0) {
            return false;
        }
    }

    return true;
}

void dfs(int num) {
    if (to_string(num).length() == n) {
        cout << num << "\n";
        return;
    }

    for (int i=1; i<10; i++) {
        if (i%2 == 0) {
            continue;
        }

        if (check(num*10 + i)) {
            dfs(num*10 + i);
        }
    }

    return;
}

int main() {
    cin >> n;

    dfs(2);
    dfs(3);
    dfs(5);
    dfs(7);

    return 0;
}