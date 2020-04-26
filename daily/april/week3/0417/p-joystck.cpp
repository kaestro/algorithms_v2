#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int beg_idx = -1, end_idx;
    if (name[1] == 'A') beg_idx = 1;
    if (beg_idx != -1) {
        int i = beg_idx;
        while (name[i] == 'A') {
            end_idx = i;
            i++;
        }
    }

    if (beg_idx == -1) {
        for (int i = 0; i < name.length(); ++i) {
            answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        }
        answer += name.length() - 1;
    } else {
        for (int i = 0; i < name.length(); ++i) {
            if (i >= beg_idx && i <= end_idx) continue;
            answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        }
        answer += name.length() - 1 - (end_idx - beg_idx + 1);
    }
    return answer;
}

int main() {
    string name = "JEROEN";
    name = "JAAN";
    auto ans = solution(name);
    return 0;
}