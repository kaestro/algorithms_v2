#include <string>
#include <vector>

using namespace std;

int answer;
int g_target;

void backtrack(int idx, int val, vector<int> &numbers);

int solution(vector<int> numbers, int target) {
    answer = 0, g_target = target;
    backtrack(0, 0, numbers);
    return answer;
}

void backtrack(int idx, int val, vector<int> & numbers) {
    if (idx == numbers.size()) {
        if (val == g_target) {
            answer++;
        }
        return;
    }

    backtrack(idx + 1, val - numbers[idx], numbers);
    backtrack(idx + 1, val + numbers[idx], numbers);
}