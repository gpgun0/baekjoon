#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, vector<int>> direction = {
    {"E", {0, 1}},
    {"W", {0, -1}},
    {"S", {1, 0}},
    {"N", {-1, 0}}
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
        
        vector<int> d = direction[ret[0]];
        int cnt = atoi(ret[1].c_str());
        
        int nx = x + cnt*d[0];
        int ny = y + cnt*d[1];
        if (nx < 0 or nx >= park.size() or ny < 0 or ny >= park[0].size()) {
            continue;
        }
        
        int dx = 0;
        int dy = 0;

        while (cnt--) {
            if (ret[0] == "E") {
                dy++;
            } else if (ret[0] == "W") {
                dy--;
            } else if (ret[0] == "S") {
                dx++;
            } else {
                dx--;
            }
            if (park[x+dx][y+dy] == 'X') {
                dx = 0;
                dy = 0;
                break;
            }
        }

        x += dx;
        y += dy;
    }
    
    return { x, y };
}