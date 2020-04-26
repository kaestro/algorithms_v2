#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> word_to_int;

bool compare(string& lhs, string &rhs) {
    int l_len = lhs.length(), r_len = rhs.length();
    int i = 0;
    while (i < l_len && i < r_len) {
        if (word_to_int[lhs[i] - 'a'] == word_to_int[rhs[i] - 'a'] ) {
            ++i; continue;
        }
        
        return word_to_int[lhs[i] - 'a'] < word_to_int[rhs[i] - 'a'];
    }
    return l_len < r_len;
}

void sort_by_order(vector <string> &words, string &alphabets) {
    word_to_int.clear();
    word_to_int = vector<int>(26);
    for (int i = 0; i < alphabets.length(); ++i) {
        word_to_int[alphabets[i] - 'a'] = i;
    }
    sort(words.begin(), words.end(), compare);
}

int main() {
    vector<string> words = {
        "we", "qwer", "erer", "qw", "errr"
    };

    string alphabets = "qwerty";

    sort_by_order(words, alphabets);

    for (auto word : words) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}