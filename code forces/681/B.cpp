#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--) {
        int explode, place;
        cin >> explode >> place;

        string line;
        cin >> line;

        int i = line.find('1');

        int result = 0;
        if (i != -1) {
            result += explode;

            while (i < line.length()) {
                while (i < line.length() && line[i] == '1') i++;

                int j = i;
                while (j < line.length() && line[j] != '1') j++;

                int minDist;
                if (j == line.length()) {
                    break;
                } else {
                    minDist = j - i;
                }

                if (minDist * place < explode) {
                    result += minDist * place;
                } else {
                    result += explode;
                }
                i = j;
            }
        }

        cout << result << endl;
    }

    return 0;
}
