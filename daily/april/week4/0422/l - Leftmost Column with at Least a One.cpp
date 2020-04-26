#include <vector>
#include <algorithm>

using namespace std;
class BinaryMatrix {
  public:
    int get(int x, int y);
    vector<int> dimensions();
};


class Solution {
private:
    int row_size, col_size;
    int binary_search(int row_idx, int l_bnd, int u_bnd);
    BinaryMatrix *BM;
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        BM = &binaryMatrix;
        auto temp = binaryMatrix.dimensions();
        row_size = temp[0], col_size = temp[1];
        int min_idx = col_size;
        for (int row = 0; row < row_size; ++row) {
            int idx = binary_search(row, 0, min_idx);
            min_idx = min(idx, min_idx);
        }
        return min_idx == col_size ? -1 : min_idx;
    }
};

int Solution::binary_search(int row_idx, int l_bnd, int u_bnd) {
    if (l_bnd == u_bnd) return col_size;

    int mid = l_bnd + u_bnd;
    int ans;
    if (BM->get(row_idx, mid) == 1) {
        int temp = binary_search(row_idx, l_bnd, mid);
        ans = temp == col_size ? mid : temp;
    } else {
        ans = binary_search(row_idx, mid, u_bnd);
    }
    return ans;
}