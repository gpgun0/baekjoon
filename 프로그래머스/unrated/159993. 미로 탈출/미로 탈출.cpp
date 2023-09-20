#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> moves = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int solution(vector<string> maps) {
    int answer = 0;
    queue<tuple<int, int, int>> q;
    set<pair<int, int>> seen;
    int dx, dy, nx, ny;
    int n = maps.size();
    int m = maps[0].size();
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maps[i][j] == 'S') {
                q.push(make_tuple(i, j, 0));
                seen.insert(make_pair(i, j));
                break;
            }
        }
    }
    
    int cnt = 0;
    bool flag = false;
    int toLeverCnt = 0;
    int toEndCnt = 0;
    
    while (!q.empty()) {
        int x = get<0>(q.front()), y = get<1>(q.front());
        cnt = get<2>(q.front());
        q.pop();
        
        if (!flag && maps[x][y] == 'L') {
            toLeverCnt += cnt;
            q = {};
            q.push(make_tuple(x, y, 0));
            seen = {};
            seen.insert(make_pair(x, y));
            flag = true;
            continue;
        }
        if (flag && maps[x][y] == 'E') {
            toEndCnt += cnt;
            break;
        }
        
        for (auto move: moves) {
            dx = move.first, dy = move.second;
            nx = x+dx, ny = y+dy;
            
            if (0 <= nx && nx < n && 0 <= ny && ny < m && maps[nx][ny] != 'X') {
                if (!seen.count(make_pair(nx, ny))) {
                    q.push(make_tuple(nx, ny, cnt+1));
                    seen.insert(make_pair(nx, ny));
                }
            }
        }
    }

    if (toLeverCnt == 0 || toEndCnt == 0) {
        return -1;
    }
    return toLeverCnt + toEndCnt;
}