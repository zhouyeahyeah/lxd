//��������
//�ж������Ƿ�
//����л�������ҵ��������??

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

// ����ڵ�Ķ���
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
            // ����ָ����������ʱ��head �� �����㣬ͬʱ����ֱ?����
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
            return index2; // ���ػ���??
            }
        }
    return NULL;
    }
};

int main() {
    // ��������ڵ�
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);

    // ������
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // ��������� node1

    // ���� Solution ����
    Solution solution;

    // ���Լ�⻷�ĺ���
    ListNode* result = solution.detectCycle(head);
    if (result != NULL) {
        cout << "�������ֵΪ: " << result->val << endl;
    } else {
        cout << "�����в����ڻ�" << endl;
    }

    // �ͷ��ڴ�
    delete head;
    delete node1;
    delete node2;
    delete node3;

    system("pause");
    return 0;
}