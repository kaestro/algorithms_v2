#include <string>
#include <vector>

using namespace std;

bool valid(int cnt, int n) {
    int res;
    res = cnt * cnt + 2 * n - cnt;
    bool isValid = res % (2 * cnt) == 0;
    if (isValid) {
        res /= (2 * cnt);
        isValid &= (res - cnt + 1) > 0;
    }
    return isValid;
}

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer += valid(i, n);
    }

    return answer;
}

int main() {
    auto ans = solution(15);
    return 0;
}