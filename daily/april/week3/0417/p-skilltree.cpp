#include <string>
#include <vector>

using namespace std;

int solution(string skill_order, vector<string> skill_trees) {
    int answer = 0;
    for (const auto &skill_tree : skill_trees) {
        int cnt = 0;
        bool possible = true;
        for (auto skill : skill_tree) {
            int idx = skill_order.find(skill);
            if (idx == -1) continue;

            if (cnt != idx) {
                possible = false;
                break;
            }
            else cnt++;
        }
        if (possible) answer++;
    }
    return answer;
}

int main() {
    string skill_order = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    solution(skill_order, skill_trees);
    
    return 0;
}