#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
map<string, int> direction = {
    {"E", 0},
    {"W", 1},
    {"S", 2},
    {"N", 3}
};

vector<string> split(string route, string delimeter) {
    int position = 0;
    vector<string> result;
    string token = "";
    
    while ((position = route.find(delimeter)) != string::npos) {
        token = route.substr(0, position);
        result.push_back(token);
        route.erase(0, position + delimeter.length());
    }

    result.push_back(route);
    return result;
}

vector<int> find_start(vector<string> park) {
    for (int i=0; i<park.size(); i++) {
        for (int j=0; j<park[0].size(); j++) {
            if (park[i][j] == 'S') {
                return { i, j };
            }
        }
    }
    return { 0, 0 };
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<int> start = find_start(park);
    int x = start[0];
    int y = start[1];

    for (auto route: routes) {
        vector<string> ret = split(route, " ");
        int d = direction[ret[0]];
        int cnt = atoi(ret[1].c_str());
        
        int nx = x;
        int ny = y;
        while (cnt--) {
            nx += dx[d], ny += dy[d];
            if (nx < 0 or nx >= park.size() or ny < 0 or ny >= park[0].size()
               or park[nx][ny] == 'X') {
                nx = x;
                ny = y;
                break;
            }
        }

        x = nx;
        y = ny;
    }
    
    return { x, y };
}