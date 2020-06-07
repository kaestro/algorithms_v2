#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        while (true) {
            auto next = node->next;
            node->val = next->val;
            if (!next->next) {
                node->next = NULL;
                break;
            }
            node = next;
        }
    }
};