//环形链表
//判断链表是否环
//如果有环，如何找到这个环的??

/**
* Definition for singly-linked list.
* struct ListNode {
* int val;
* ListNode *next;
* ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <iostream>
using namespace std;

// 链表节点的定义
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
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直?相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
            return index2; // 返回环的??
            }
        }
    return NULL;
    }
};

int main() {
    // 创建链表节点
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);

    // 构建环
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // 环的入口是 node1

    // 创建 Solution 对象
    Solution solution;

    // 测试检测环的函数
    ListNode* result = solution.detectCycle(head);
    if (result != NULL) {
        cout << "环的入口值为: " << result->val << endl;
    } else {
        cout << "链表中不存在环" << endl;
    }

    // 释放内存
    delete head;
    delete node1;
    delete node2;
    delete node3;

    system("pause");
    return 0;
}