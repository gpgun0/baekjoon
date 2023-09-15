#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> dict;
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for (int i=0; i<name.size(); i++) {
        dict[name[i]] = yearning[i];
    }
    
    int score = 0;
    for (auto members: photo) {
        for (auto member: members) {
            score += dict[member];
        }
        answer.push_back(score);
        score = 0;
    }
    
    return answer;
}