#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *walker = head, *runner = head;

        if (!head->next || !head->next->next) return NULL;

        walker = walker->next;
        runner = runner->next->next;
        while (!walker && !runner && walker != runner) {
            runner = runner->next; if (!runner) return NULL;
            runner = runner->next; if (!runner) return NULL;
            walker = walker->next;
        }

        ListNode *entrance = head;
        while (entrance != walker) {
            entrance = entrance->next;
            walker = walker->next;
        }
        return entrance;
    }
};