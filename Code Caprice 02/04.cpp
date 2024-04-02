/**
 * 两两交换链表中的节点
 * 给定⼀个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，⽽是需要实际的进⾏节点交换。
*/


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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 设置⼀个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样⽅⾯后⾯做删除操作
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* temp=cur->next;
            ListNode* temp1=cur->next->next->next;
            cur->next=cur->next->next;
            cur->next->next=temp;
            cur->next->next->next=temp1;
            cur=cur->next->next;
        }
    return dummyHead->next;
    }
};

int main() {
    // 创建链表：1->2->3->4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // 调用 swapPairs 方法
    Solution solution;
    ListNode* newHead = solution.swapPairs(head);

    // 打印交换后的链表
    ListNode* current = newHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    system("pause");

    // 释放内存
    current = newHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
