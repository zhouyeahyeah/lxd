#include<iostream>
using namespace std;

// 单链表
struct ListNode {
int val; // 节点上存储的元素
ListNode *next; // 指向下⼀个节点的指针
ListNode(int x) : val(x), next(NULL) {} // 节点的构造函数
};

//直接使用原来的链表进行移除操作
class Solution01
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        //删除头节点
        while(head!=NULL&&head->val==val)
        {
            ListNode* temp;
            temp=head;
            head=head->next;
            delete temp;
        }

        //删除非头节点
        ListNode* cur=head;
        while(cur!=NULL&&cur->next!=NULL)
        {
            if(cur->next->val==val)
            {
                ListNode* temp;
                temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
            else{
                cur=cur->next;
            }
        }
        return head;
    }
};

//设置⼀个虚拟头结点在进⾏移除节点操作：
class Solution02
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* dummyHead = new ListNode(0); // 设置⼀个虚拟头结点
        dummyHead->next=head;
        ListNode* cur=dummyHead;
        while(cur->next!=NULL)
        {
            if(cur->next->val==val)
            {
                ListNode* temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
            else{
                cur=cur->next;
            }
        }
        return head;
    }
};

int main()
{
    // 创建链表: 1->2->6->3->4->5->6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    //Solution01 solution;
    Solution02 solution;
    // 测试删除值为 6 的节点
    ListNode* newHead = solution.removeElements(head, 6);

    // 打印删除后的链表
    ListNode* current = newHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    system("pause");

    // 释放链表的内存
    current = newHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
