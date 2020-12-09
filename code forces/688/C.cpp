#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Points {
public:
    Points(int num, int matSize) {
        this->num = num;
        pointsByRow = vvi(matSize);
        pointsByCol = vvi(matSize);
        pointsCnt = 0;
    }

    int num;
    vvi pointsByRow;
    vvi pointsByCol;
    int pointsCnt;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> matrix;
        vector<Points> vPoints;
        for (int i = 0; i < 10; ++i) {
            vPoints.push_back(Points(i, n));
        }

        matrix.reserve(n);
        for (int i = 0; i < n; ++i) {
            string num;
            cin >> num;
            matrix.push_back(num);
        }

        for (int i = 0; i < n; ++i) {
            string& row = matrix[i];
            for (int j = 0; j < n; ++j) {
                int num = row[j] - '0';
                vPoints[num].pointsCnt++;
                vPoints[num].pointsByRow[i].push_back(j);
                vPoints[num].pointsByCol[j].push_back(i);
            }
        }

        vector<int> ans;
        for (auto& points : vPoints) {
            if (points.pointsCnt < 2) {
                ans.push_back(0);
                continue;
            }

            int maxSize = 0;
            int num = points.num;
            for (int i = 0; i < n; ++i) {
                auto& row = points.pointsByRow[i];
                if (row.size() == 0) continue;

                int row_len;
                int col_len;
                if (row.size() == 1) {
                    row_len = max(abs(0 - row[0]), n - row[0] - 1);
                    col_len = 0;
                    for (int j = 0; j < n; ++j) {
                        if (points.pointsByRow[j].empty()) continue;

                        col_len = max(col_len, abs(j - i));
                    }

                    maxSize = max(maxSize, row_len * col_len);
                } else {
                    row_len = row.back() - row.front();
                    col_len = max(i - 0, n - i - 1);
                    maxSize = max(maxSize, row_len * col_len);

                    if (points.pointsCnt != row.size()) {
                        row_len = max(row.back(), n - row.front() - 1);
                        col_len = 0;
                        
                        for (int j = 0; j < n; ++j) {
                            if (points.pointsByRow[j].empty()) continue;

                            col_len = max(col_len, abs(j - i));
                        }

                        maxSize = max(maxSize, row_len * col_len);
                    }
                }

            }

            for (int i = 0; i < n; ++i) {
                auto& row = points.pointsByCol[i];
                if (row.size() == 0) continue;

                int row_len;
                int col_len;
                if (row.size() == 1) {
                    row_len = max(abs(0 - row[0]), n - row[0] - 1);
                    col_len = 0;
                    for (int j = 0; j < n; ++j) {
                        if (points.pointsByCol[j].empty()) continue;

                        col_len = max(col_len, abs(j - i));
                    }

                    maxSize = max(maxSize, row_len * col_len);
                } else {
                    row_len = row.back() - row.front();
                    col_len = max(i - 0, n - i - 1);
                    maxSize = max(maxSize, row_len * col_len);

                    if (points.pointsCnt != row.size()) {
                        row_len = max(row.back(), n - row.front() - 1);
                        col_len = 0;
                        
                        for (int j = 0; j < n; ++j) {
                            if (points.pointsByCol[j].empty()) continue;

                            col_len = max(col_len, abs(j - i));
                        }

                        maxSize = max(maxSize, row_len * col_len);
                    }
                }

            }

            ans.push_back(maxSize);
        }

        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}