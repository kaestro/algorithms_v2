#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        vector<int> nums(N);
        for (int j = 0; j < N; ++j) {
            cin >> nums[j];
        }

        int ans = 0;
        int max_val = -1;
        for (int j = 0; j < N; ++j) {
            if (nums[j] > max_val)  {
                max_val = nums[j];
                if (j < N - 1 && max_val > nums[j + 1]) {
                    ++ans;
                } else if (j == N - 1) {
                    ++ans;
                }
            }
        }
        cout << "Case #" << i << ":" << " " << ans << endl;
    }
    return 0;
}
