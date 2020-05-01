extern bool isBadVersion(int n);

class Solution {
private:
    int binary_search(int l_bnd, int u_bnd) {
        if (l_bnd > u_bnd) return -1;
        
        int mid = ((long long)l_bnd + (long long)u_bnd) / 2;
        bool flag = isBadVersion(mid);
        if (flag) {
            int lower =  binary_search(l_bnd, mid - 1);
            if (lower == -1) return mid;
            else return lower;
        } else {
            return binary_search(mid + 1, u_bnd);
        }
    }
public:
    int firstBadVersion(int n) {
        return binary_search(1, n);
    }
};