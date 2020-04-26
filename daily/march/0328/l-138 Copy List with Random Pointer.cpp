#include <map>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> copyList;
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        if (copyList.find(head) == copyList.end()) {
            copyList[head] = new Node(head->val);
            copyList[head]->next = copyRandomList(head->next);
            copyList[head]->random = copyRandomList(head->random);
        }

        return copyList[head];
    }
};

int main() {
    return 0;
}