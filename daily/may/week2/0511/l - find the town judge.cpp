#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> people(N);
        for (auto temp : trust) {
            int &trusting_person = people[temp[0] - 1];
            int &trusted_person = people[temp[1] - 1];

            trusting_person = -1;
            if (trusted_person == -1) continue;
            trusted_person++;
        }

        int answer = -1;
        for (int person_idx = 0; person_idx < N; ++person_idx) {
            int trusting_cnt = people[person_idx];
            if (trusting_cnt == N - 1) {
                answer = person_idx + 1;
                break;
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    vvi trust = {{1,2}};
    int N = 2;

    auto ans = s.findJudge(N, trust);
    
    N = 3;
    trust = {{1,3},{2,3},{3,1}};

    return 0;
}