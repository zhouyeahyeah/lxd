//环形链表II
//给定⼀个链表，返回链表开始⼊环的第⼀个节点。 如果链表⽆环，则返回 null


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
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直⾄相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
            return index2;
            }
        }
    return NULL;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; 

    Solution solution;

    ListNode* result = solution.detectCycle(head);
    if (result != NULL) {
        cout << "result's val: " << result->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    delete head;
    delete node1;
    delete node2;
    delete node3;

    system("pause");
    return 0;
}