#include <string>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

bool num_valid[1000] = {false};

void set_nums();
vi judge(int lhs, int rhs);
int solution(vvi);

int main() {
    vvi baseballs = {{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}};
    auto ans = solution(baseballs);
    return 0;
}



int solution(vector<vector<int>> baseballs) {
    int answer = 0;
    set_nums();
    for (auto baseball : baseballs) {
        for (int i = 0; i < 1000; ++i) {
            if (num_valid[i]) {
                vi res = judge(baseball[0], i);
                if (res[0] != baseball[1] || res[1] != baseball[2])
                    num_valid[i] = false;
            }
        }
    }

    for (int i = 0; i < 1000; ++i) {
        answer += num_valid[i];
    }
    return answer;
}

void set_nums() {
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            if (j == i) continue;
            for (int k = 1; k < 10; ++k) {
                if (i == k || j == k) continue;
                num_valid[100 * i + 10 * j + k] = true;
            }
        }
    }
}

vi judge(int lhs, int rhs) {
    vi res = {0, 0};
    int chk[10] = {0};

    for (int i = 0; i < 3; ++i) {
        if (lhs % 10 == rhs % 10) {
            res[0]++;
        } else {
            chk[lhs % 10]++;
            chk[rhs % 10]++;
        }

        if (chk[lhs % 10] == 2)
            res[1]++;
        
        if (chk[rhs % 10] == 2)
            res[1]++;

        lhs /= 10;
        rhs /= 10;
    }
    return res;
}