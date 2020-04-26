#include <iostream>

using namespace std;

int main() {
    int M, N, T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> M >> N;
        int sum = M + N;
        int tempN = N, tempSum = sum;
        while (tempN > 0) {
            tempN /= 10, tempSum /= 10;
        }
        cout << (tempN == tempSum ? N : sum) << endl;
    }
	return 0;
}