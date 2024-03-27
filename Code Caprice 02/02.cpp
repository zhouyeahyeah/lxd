/**
 * 设计链表
 * 在链表类中实现这些功能：
get(index)：获取链表中第 index 个节点的值。如果索引⽆效，则返回-1。
addAtHead(val)：在链表的第⼀个元素之前添加⼀个值为 val 的节点。插⼊后，新节点将成为链表的第⼀个节
点。
addAtTail(val)：将值为 val 的节点追加到链表的最后⼀个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val 的节点。如果 index 等于链表的⻓
度，则该节点将附加到链表的末尾。如果 index ⼤于链表⻓度，则不会插⼊节点。如果index⼩于0，则在头
部插⼊节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
*/

#include<iostream>
using namespace std;

class MyLinkedList 
{
public:
    // 定义链表节点结构体
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
    };

    //初始化链表
    MyLinkedList()
    {
        _dummyHead = new LinkedNode(0);// 这⾥定义的头结点 是⼀个虚拟头结点，⽽不是真正的链表头结点
        _size=0;
    }

    // 获取到第index个节点数值，如果index是⾮法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index)
    {
        if(index>_size-1||index<0)
        {
            return -1;
        }
        else{
            LinkedNode* cur=_dummyHead->next;
            while(index)
            {
                cur=cur->next;
                index--;
            }
            return cur->val;
        }
    }

    // 在链表最前⾯插⼊⼀个节点，插⼊完成后，新插⼊的节点为链表的新的头结点
    void addAtHead(int val) {
        LinkedNode* newNode= new LinkedNode(val);
        newNode->next=_dummyHead->next;
        _dummyHead->next=newNode;
        _size++;
    }

    // 在链表最后⾯添加⼀个节点
    void addAtTail(int val) {
        LinkedNode* newNode= new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next!=nullptr)
        {
            cur=cur->next;
        }
        cur->next=newNode;
        _size++;
    }

    // 在索引为index的节点之前插⼊⼀个新节点，例如index为0，那么新插⼊的节点为链表的新头节点。
    // 如果index 等于链表的⻓度，则说明是新插⼊的节点为链表的尾结点
    // 如果index⼤于链表的⻓度，则返回空
    // 如果index⼩于0，则在头部插⼊节点
    void addAtIndex(int index, int val) {
        if(index>_size) return;
        if(index<0)  index=0;
        LinkedNode* newNode= new LinkedNode(val);
        LinkedNode* cur=_dummyHead;
        while(index)
        {
            cur=cur->next;
            index--;
        }
        newNode->next=cur->next;
        cur->next=newNode;
        _size++;
    }

    // 删除索引为index的节点，如果index ⼤于等于链表的⻓度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if(index>=_size|| index < 0) return;
        LinkedNode* temp;
        LinkedNode* cur=_dummyHead;
        while(index)
        {
            cur=cur->next;
            index--;
        }
        temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
        //delete命令指示释放了temp指针原本所指的那部分内存，
        //被delete后的指针temp的值（地址）并⾮就是NULL，⽽是随机值。也就是被delete后，
        //如果不再加上⼀句temp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不⼩⼼使⽤了temp，会指向难以预想的内存空间
        temp = nullptr;
        _size--;
    }

    // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) 
        {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
            cout << endl;
    }

private:
    int _size;
    LinkedNode* _dummyHead;
};

int main() {
    MyLinkedList linkedList;

    // 在链表头部插入节点
    linkedList.addAtHead(1);
    linkedList.printLinkedList(); // 输出: 1

    // 在链表尾部添加节点
    linkedList.addAtTail(3);
    linkedList.printLinkedList(); // 输出: 1 3

    // 在索引为1的位置插入节点
    linkedList.addAtIndex(1, 2);  
    linkedList.printLinkedList(); // 输出: 1 2 3

    // 获取索引为1的节点的值
    int val = linkedList.get(1);
    cout << "Value at index 1: " << val << endl; // 输出: Value at index 1: 2

    // 删除索引为1的节点
    linkedList.deleteAtIndex(1); 
    linkedList.printLinkedList(); // 输出: 1 3

    // 再次获取索引为1的节点的值
    val = linkedList.get(1);
    cout << "Value at index 1: " << val << endl; // 输出: Value at index 1: 3

    system("pause");

    return 0;
}
