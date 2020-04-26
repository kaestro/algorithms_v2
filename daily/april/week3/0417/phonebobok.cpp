#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class trie{
private:
    trie* trie_map[10] = {0};
    bool is_phone_number = false;
public:
    bool insert(string phone_numbber) {
        trie* cur = this;
        for (auto num : phone_numbber) {
            int i_num = num - '0';
            if (!cur->trie_map[i_num]) {
                cur->trie_map[i_num] = new trie();
            }
            cur = cur->trie_map[i_num];
            if (cur->is_phone_number) return true;
        }
        cur->is_phone_number = true;
        return false;
    }
};

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    trie root;
    for (const auto &phone_number: phone_book) {
        if (root.insert(phone_number)) return false;
    }
    return true;
}

int main() {
    vector<string> phone_book = {"119", "97674223", "1195524421"};
    auto ans = solution(phone_book);
    return 0;
}