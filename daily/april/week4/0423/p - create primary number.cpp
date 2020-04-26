#include <vector>
#include <iostream>
using namespace std;


vector<bool> is_primary_number(1001);


void set_primary_number() {
    for (int i = 1; i < 1001; ++i) {
        bool flag = true;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        is_primary_number[i] = flag;
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    set_primary_number();

    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            for (int k = j + 1; k < len; ++k) {
                answer += is_primary_number[nums[i] + nums[j] + nums[k]];
            }
        }
    }

    return answer;
}

int main() {
    vector<int> nums = {1,2,3,4};
    nums = {1,2,7,6,4};
    auto ans = solution(nums);
    return 0;
}