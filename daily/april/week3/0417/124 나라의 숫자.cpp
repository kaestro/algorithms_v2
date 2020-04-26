#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int rmd;
    while (n > 0) {
        rmd = n % 3;
        n /= 3;

        if (!rmd) {
            n -= 1;
            rmd = 4;
        }
        answer.insert(answer.begin(), rmd + '0');
    }
    return answer;
}