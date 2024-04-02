//给你⼀个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

#include<iostream>
using namespace std;

// 单链表
struct ListNode {
int val; // 节点上存储的元素
ListNode *next; // 指向下⼀个节点的指针
ListNode(int x) : val(x), next(NULL) {} // 节点的构造函数
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0) return head; // 如果链表为空或n不合法，直接返回原链表

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;

        // fast指针先前进n步
        for (int i = 0; i < n; ++i) {
            if (fast->next == NULL) return head; // 如果n大于链表长度，直接返回原链表
            fast = fast->next;
        }

        // 让fast和slow一起前进，直到fast指向最后一个节点
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // 删除节点
        ListNode* toBeDeleted = slow->next;
        slow->next = slow->next->next;
        delete toBeDeleted; // 释放被删除节点的内存

        ListNode* newHead = dummyHead->next;
        delete dummyHead; // 释放哑节点的内存，避免内存泄露
        return newHead;
    }
};

int main() {
    // 创建测试链表1->2->3->4->5
    ListNode* testList = new ListNode(1);
    testList->next = new ListNode(2);
    testList->next->next = new ListNode(3);
    testList->next->next->next = new ListNode(4);
    testList->next->next->next->next = new ListNode(5);

    ListNode* temp = testList;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    
    Solution solution;
    // 删除倒数第2个节点
    ListNode* result = solution.removeNthFromEnd(testList, 2);

    while(result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    system("pause");
    return 0;
}

