#include <algorithm>
#include <vector>

using namespace std;

int findRank(vector<int> &pre_sum, int n, int num) {
    int cnt = 0;
    int sum_before_ith_index = 0;
    for (int i = 0; i < n; ++i) {
        cnt += upper_bound(pre_sum.begin(), pre_sum.end(), sum_before_ith_index + num) - pre_sum.begin() - i;
        sum_before_ith_index = pre_sum[i];
    }
    return cnt;
}

int findKthSmallestSum(int a[], int n, int k) {
    vector<int> pre_sum(n);
    int subsum = 0;
    for (int i = 0; i < n; ++i) {
        subsum += a[i];
        pre_sum[i] = subsum;
    }

    int start = 0, end = pre_sum[n-1];
    int ans = 0;
    while (start < end) {
        int mid = (start + end) / 2;

        if (findRank(pre_sum, n, mid) >= k) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int k = 13;

    auto ans = findKthSmallestSum(a, sizeof(a) / sizeof(a[0]), k);
    return 0;
}