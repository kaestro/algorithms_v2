#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sum(vector<int>& vi) {
    int res = 0;
    for (auto i : vi) {
        res += i;
    }
    return res;
}

int solution(string name) {
    int answer = 0;
    vector<int> diffs(name.length());
    for (int i = 0; i < name.length(); ++i) {
        diffs[i] = min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    
    int left_diff = name.length() - 1, right_diff = 1;
    int left_ans, right_ans;

    int where = 0;
    while (true) {
        left_ans = 0, right_ans = 0;
        answer += diffs[where];
        diffs[where] = 0;
        if (sum(diffs) == 0) break;

        int left_idx = where;
        int left_ans = 0, right_ans = 0;
        while (diffs[left_idx] == 0) {
            left_idx = (left_idx + left_diff) % name.length();
            left_ans++;
        }

        int right_idx = where;
        while (diffs[right_idx] == 0) {
            right_idx = (right_idx + right_diff) % name.length();
            right_ans++;
        }

        if (left_ans < right_ans) {
            where = left_idx;
            answer += left_ans;
        } else {
            where = right_idx;
            answer += right_ans;
        }
    }

    return answer;
}