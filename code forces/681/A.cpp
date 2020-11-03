#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int temp = 2 * n;
        while (n--) {
            temp += 2;
            cout << temp << " ";
        }
        cout << endl;
    }
    return 0;
}