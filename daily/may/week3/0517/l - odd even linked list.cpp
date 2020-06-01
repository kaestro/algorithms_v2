#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_head = head, *odd_cur = head;
        if (!odd_head) return nullptr;
        ListNode *even_head = head->next, *even_cur = head->next;
        if (!even_head) return head;
        while (true) {
            if (!odd_cur->next->next) break;
            odd_cur->next = odd_cur->next->next;
            odd_cur = odd_cur->next;
            if (even_cur->next->next) {
                even_cur->next = even_cur->next->next;
                even_cur = even_cur->next;
            } else {
                break;
            }
        }
        even_cur->next = nullptr;
        odd_cur->next = even_head;
        return odd_head;
    }
};

ListNode *insert_node(ListNode *cur, int val) {
    cur->next = new ListNode(val);
    cur = cur->next;
    return cur;
}

int main() {
    Solution s;

    ListNode *root;
    ListNode *cur;

    int num_node;
    cout << "what's the total number of list you want to create: ";
    cin >> num_node;
    for (int i = 0; i < num_node; ++i) {
        int val;
        cout << "val: ";
        cin >> val;
        if (i == 0)  {
            root = new ListNode(val);
            cur = root;
        } else {
            cur = insert_node(cur, val);
        }
    }

    auto ans = s.oddEvenList(root);

    return 0;
}