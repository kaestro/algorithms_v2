#include <string>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vvi answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    for (int row = 0; row < arr1.size(); ++row) {
        for (int col = 0; col < arr2[0].size(); ++col) {
            for (int i = 0; i < arr1[0].size(); ++i) {
                answer[row][col] += arr1[row][i] * arr2[i][col];
            }
        }
    }
    return answer;
}