//链表相交
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
    ListNode*getIntersectionNode(ListNode*headA, ListNode*headB) {
        ListNode* cur_A = headA;
        ListNode* cur_B = headB;
        int Len_A=0,Len_B = 0;
        while(cur_A!=NULL)
        {
            Len_A++;
            cur_A = cur_A->next;
        }
        while(cur_B!=NULL)
        {
            Len_B++;
            cur_B = cur_B->next;
        }

        cur_A=headA;
        cur_B=headB;

        // 让curA为最⻓链表的头，lenA为其⻓度
        if(Len_B>Len_A)
        {
            swap(Len_A,Len_B);
            swap(cur_A,cur_B);
        }

        int gap=Len_A-Len_B;

        // 让curA和curB在同⼀起点上（末尾位置对⻬）
        while(gap--)
        {
            cur_A = cur_A->next;
        }

        // 遍历curA 和 curB，遇到相同则直接返回
        while(cur_A!=NULL)
        {
            if(cur_A==cur_B)
            {
                return cur_A;
            }
            cur_A = cur_A->next;
            cur_B = cur_B->next;
        }
    return NULL;
    }
};

int main() {
    // 创建测试链表
    // 链表A: 1->2->3->4->5
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    
    // 链表B: 9->4->5 (与A相交于节点4)
    ListNode *headB = new ListNode(9);
    headB->next = headA->next->next->next; // 让B与A在节点4处相交
    
    Solution solution;
    ListNode *intersectionNode = solution.getIntersectionNode(headA, headB);
    if(intersectionNode != NULL) {
        cout << "The intersection node's value is: " << intersectionNode->val << endl;
    } else {
        cout << "The lists do not intersect." << endl;
    }

    system("pause");
    
    return 0;
}