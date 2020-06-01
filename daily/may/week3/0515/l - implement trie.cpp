#include <string>
#include <iostream>

using namespace std;

class Trie {
private:
    Trie *next_Trie[26] = {0};
    bool is_word = false;
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *cur_Trie = this;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (!cur_Trie->next_Trie[idx]) cur_Trie->next_Trie[idx] = new Trie();
            cur_Trie = cur_Trie->next_Trie[idx];
        }
        cur_Trie->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *cur_Trie = this;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (!cur_Trie->next_Trie[idx]) return false;
            cur_Trie = cur_Trie->next_Trie[idx];
        }
        return cur_Trie->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *cur_Trie = this;
        for (auto ch : prefix) {
            int idx = ch - 'a';
            if (!cur_Trie->next_Trie[idx]) return false;
            cur_Trie = cur_Trie->next_Trie[idx];
        }
        return true;
    }
};

void print_false_true(bool flag) {
    if (flag) cout << "True" << endl;
    else cout << "False" << endl;
}

int main() {
    Trie trie;
    trie.insert("apple");
    print_false_true(trie.search("apple"));   // returns true
    print_false_true(trie.search("app"));   // returns true
    print_false_true(trie.startsWith("app"));   // returns true
    trie.insert("app");   
    print_false_true(trie.search("app"));
    return 0;
}