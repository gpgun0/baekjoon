#include <bits/stdc++.h>

using namespace std;
int n;

int main() {
    cin >> n;

    string s = to_string(n);
    int result = 0;

    for (int i=0; i<s.size(); i++) {
        if (i<s.size()/2) {
            result += (int)s[i];
        } else {
            result -= (int)s[i];
        }
    }

    if (result == 0) {
        cout << "LUCKY" << "";
    } else {
        cout << "READY" << "";
    }

    return 0;
}
