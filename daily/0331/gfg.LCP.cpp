#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Trie {
private:
    unordered_map<char, Trie*> ct_map;
    string prefix = "", max_prefix = "";
public:
    string get_max_prefix() {
        return max_prefix;
    }
    void create_Trie(string input) {
        auto cur = this;
        for (int i = 0; i < input.length(); ++i) {
            auto c = input[i];
            if (cur->ct_map.find(c) == cur->ct_map.end()) {
                cur->ct_map[c] = new Trie();
            }
            cur = cur->ct_map[c];
            if (cur->prefix != "") {
                if (max_prefix.length() < cur->prefix.length()) {
                    max_prefix = cur->prefix;
                }
            }
        }
        cur->prefix = input;
    }
};

bool comp_strlen(string& lhs, string &rhs) {
    return lhs.length() < rhs.length();
}

string LCP(string ar[], int n)
{
    sort(ar, ar + n, comp_strlen);
    Trie *root = new Trie();
    for (int i = 0; i < n; ++i) {
        root->create_Trie(ar[i]);
    }
    return root->get_max_prefix();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string *arr = new string[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << LCP(arr, n) << endl;
        delete [] arr;
    }
}