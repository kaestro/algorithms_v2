#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        if (A.size() <= K) return A.size();
        int num_zero = 0;

        int ans = 0;
        int start_idx = 0;
        for (int end_idx = 0; end_idx < A.size(); ++end_idx) {
            if (A[end_idx] == 0) num_zero++;

            if (num_zero > K) {
                while (start_idx <= end_idx) {
                    if (A[start_idx] == 0) num_zero--;
                    start_idx++;
                    if (num_zero == K) break;
                }
            }

            if (num_zero <= K) ans = max(ans, end_idx - start_idx + 1);
        }

        return ans;
    }
};

int main() {
    Solution S;
    vector<int> A = {1,1,1,0,0,0,1,1,1,1,0}; 
    A = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    S.longestOnes(A, 3);
    return 0;
}