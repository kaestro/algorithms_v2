#include <algorithm>

using namespace std;

int gcd(int lhs, int rhs) {
    int temp = max(lhs, rhs);
    rhs = min(lhs, rhs);
    lhs = temp;

    while (true) {
        int temp = lhs % rhs;
        if (temp == 0) break;

        lhs = rhs, rhs = temp;
    }
    return rhs;
}

long long solution(int w,int h)
{
    int div = gcd(w, h);
	return w * h - div * (w / div + h / div - 1);
}