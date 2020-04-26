#include <string>
#include <vector>

using namespace std;

typedef struct {
    int strike, ball;
} Result;

bool num_valid[1000] = {false};
vector<int> nums;

Result judge(int lhs, int rhs);
int set_nums();
int solution(vector<vector<int>> baseballs);

int main() {
    vector<vector<int>> baseballs = {{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}};
    auto ans = solution(baseballs);
    return 0;
}

int set_nums() {
    for (int i = 123; i < 988; ++i) {
        int digits[3];
        digits[0] = i / 100;
        digits[1] = i / 10 % 10;
        digits[2] = i % 10;
        if (digits[0] * digits[1] * digits[2] == 0) continue;
        if (digits[0] == digits[1] || digits[0] == digits[2])
            continue;
        if (digits[1] == digits[2])
            continue;
        
        nums.push_back(i);
        num_valid[i] = true;
    }
}


int solution(vector<vector<int>> baseballs) {
    set_nums();
    int answer = 0;
    for (auto baseball : baseballs) {
        for (auto num : nums) {
            if (num_valid[num]) {
                Result res = judge(num, baseball[0]);
                if (res.strike != baseball[1] || res.ball != baseball[2])
                    num_valid[num] = false;
            }
        }
    }

    for (int i = 0; i < 1000; ++i) {
        answer += num_valid[i];
    }

    return answer;
}

Result judge(int lhs, int rhs) {
    Result res;
    res.strike = 0, res.ball = 0;

    int chk[10] = {0};

    for (int i = 0; i < 3; ++i) {
        if (lhs % 10 == rhs % 10) {
            res.strike++;
        } else {
            chk[lhs % 10]++, chk[rhs % 10]++;
        }

        if (chk[lhs % 10] == 2) res.ball++;
        if (chk[rhs % 10] == 2) res.ball++;

        lhs /= 10, rhs /= 10;
    }
    return res;
}