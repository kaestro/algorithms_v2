#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime = vector<bool>(401, true);
vector<int> primes;

void setPrimes() {
    isPrime[0] = false;
    isPrime[1] = false;
    primes.reserve(100);
    for (int i = 2; i < 401; ++i) {
        if (isPrime[i]) {
            for (int j = i + 1; j < 401; ++j) {
                isPrime[j] = isPrime[j] * !((j % i) == 0);
            }
            primes.push_back(i);
        }
    }
}

int main() {
    int t;
    cin >> t;
    setPrimes();
    while (t--) {
        int n;
        cin >> n;
        vector<int> answer;
        answer.reserve(n);
        int multiple = 2;
        while (n--) {

        }
    }
}