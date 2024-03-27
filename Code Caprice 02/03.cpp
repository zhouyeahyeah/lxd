#include<iostream>
using namespace std;

// 单链表
struct ListNode {
int val; // 节点上存储的元素
ListNode *next; // 指向下⼀个节点的指针
ListNode(int x) : val(x), next(NULL) {} // 节点的构造函数
};

//反转链表

//双指针法   
class Solution
{
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* pre=NULL;
        ListNode* cur=head;
        while(cur)
        {
            temp=cur->next;// 保存⼀下 cur的下⼀个节点，因为接下来要改变cur->next
            cur->next=pre;// 翻转操作
            pre=cur;
            cur=temp;
        }
        return pre;
    }
};

//递归法
class Solution02 
{
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进⾏对⽐，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是⼀样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }
};

int main() {
    // 创建链表: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 输出原始链表
    cout << "Original List: ";
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // 反转链表
    // Solution solution;
    Solution02 solution;
    ListNode* reversedHead = solution.reverseList(head);

    // 输出反转后的链表
    cout << "Reversed List: ";
    cur = reversedHead;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // 释放内存
    cur = reversedHead;
    while (cur != nullptr) {
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }

    system("pause");

    return 0;
}
