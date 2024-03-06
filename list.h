#pragma once
#include<assert.h>
#include<algorithm>
using namespace std;

using namespace std;

namespace lwd
{
    // List的节点类
    //struct默认成员公有，方便List类访问成员
    template<class T>
    struct ListNode
    {
        
        ListNode(const T& val = T())
            : _pPre(nullptr)
            , _pNext(nullptr)
            ,_val(val)
        {}
        
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List的迭代器类
    //迭代器部分是整个List最精华的部分
    //我们需要深刻的理解迭代器是为了模拟指针行为这句话
    template<class T, class Ref, class Ptr>
    class ListIterator
    {
        typedef ListNode<T>* PNode;
        //这三个类模版的参数十分有讲究，详细移步List类中的typedef查看
        //typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, Ref, Ptr> Self;
    public:
        //List的迭代器类的构造函数
        ListIterator(PNode pNode = nullptr)
            : _pNode(pNode)
        {}

        //拷贝构造
        ListIterator(const Self& l)
        {
            _pNode = l._pNode;
        }
        //这样是不行的，因为无法区分const迭代器
        //T& operator*()
        //正确的=》
        Ref operator*()
        {
            return _pNode->_val;
        }
        //当Ref为const类时返回的就是const类的引用，只读，不可修改

        //先分析一下->的作用，我们知道List的迭代器是为了模仿指针的行为，而这里的->便是在实例化类型T为自定义类时起作用的
        // 我们的->期望返回到List的T类成员的指针，库中选择返回我们节点的指针实现，这里的实际使用语法应该"->->"双重叠加，
        // 而编译器实际使用时做了优化，解释不清。
        //这样是不行的，因为无法区分const迭代器
        //T* operator->()
        Ptr operator->()
        {
            return &_pNode->_val;
        }

        //这里++重载便是对迭代器模仿指针行为的最好诠释
        Self& operator++()
        {
            //++操作实际是自加，所以我们应该修改当前迭代器本身的成员指针存的节点值，而不是单纯返回成员指针的next位置
            // 虽然这里编译器会做隐式类型装换，但是转换的变量无名无姓，而指定返回的又是一个引用，我们理所应当的认为它
            // 会报错
            //return _pNode->_pNext;
            _pNode = _pNode->_pNext;
            return *this;
        }

        //这里不能返回引用，因为返回的是一个临时变量，我们后置++要求的是返回原值再进行++操作
        Self operator++(int)
        {
            Self tmp = _pNode;
            _pNode = _pNode->_pNext;
            return tmp;
        }

        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }

        Self& operator--(int)
        {
            Self tmp = _pNode;
            _pNode = _pNode->_pPre;
            return tmp;
        }

        bool operator!=(const Self& l)
        {
            return _pNode != l._pNode;
        }

        bool operator==(const Self& l)
        {
            return _pNode == l._pNode;
        }

        PNode _pNode;
    };

    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
        ///
        ///
        void Emptyinit()
        {
            _pHead = new Node;
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
        }
        // List的无参构造
        list()
        {
            Emptyinit();
        }

        list(int n, const T& value = T())
        {
            Emptyinit();
            for (int i = 0; i < n; i++)
            {
                insert(end(), value);
            }
        }

                template <class Iterator>
        list(Iterator first, Iterator last)
        {
        	Emptyinit();
            while (first != last)
            {
                push_back(*first);
                ++ first;
            }
        }

        list(const list<T>& l)
        {
            Emptyinit();
            //这里最好用引用，因为万一List是用一个自定义类型实例化的，可以大大提升效率
            //分析下如果不用引用：我们知道范围for是用迭代器实现的，编译器也只是简单的对范围for进行替换而已
            //如果不用引用，编译器需要用迭代器逐个遍历，遍历一个便赋值给e变量，这便是效率的关键，如果不用引用，每次
            //赋值给e都需要调用一次迭代器类的拷贝函数
            for (auto &e : l)
            {
                push_back(e);
            }
        }

        //赋值重载函数
        list<T>& operator=(list<T> l)
        {
            swap(l);
            return *this;
        }

        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
            Lsize = 0;
        }

        // List Iterator
        iterator begin()
        {
            return _pHead->_pNext;
            //这里返回的很奇怪，我们不是要求一个迭代器类吗，它返回一个List节点类干嘛？
            //别忘了单参数构造函数的类可以隐式类型装换，这里节点返回时便被包装成了迭代器类
        }
        iterator end()
        {
            return _pHead;
        }
        //我们这里对const迭代器的区别是在迭代器类的内部实现的，我们这里单独为const迭代器重载只是单纯为了让它能正常
        //调用begin和end函数，因为const迭代器是无法被正常迭代器的begin函数识别的，因为它们的参数不同。
        const_iterator begin() const
        {
            return _pHead->_pNext;
        }
        const_iterator end() const
        {
            return _pHead;
        }

        // List Capacity
        size_t size()const
        {
            return Lsize;
        }
        bool empty()const
        {
            return Lsize == 0;
        }

        // List Access
        T& front()
        {
            return _pHead->_pNext->_val;
        }
        const T& front()const
        {
            return _pHead->_pNext->_val;
        }
        T& back()
        {
            return  _pHead->_pPre->_val;
        }
        const T& back()const
        {
            return _pHead->_pPre->_val;
        }

        // List Modify
        void push_back(const T& val) 
        //这样是比较偏现代的写法
        { 
            insert(end(), val); 
        }

        void pop_back() 
        { 
            erase(--end()); 
        }
        void push_front(const T& val) 
        { 
            insert(begin(), val); 
        }
        void pop_front() 
        { 
            erase(begin()); 
        }

                // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            //先存住pos迭代器成员变量（List节点变量）的前一个List节点，方便连接
            Node* cur = pos._pNode;
            Node* prev = cur->_pPre;
            //Node* next = cur->_pNext;
            //创建一个新的List节点
            Node* newNode = new Node(val);
            //改变双向链表的两个指针完成连接
            prev->_pNext = newNode;
            newNode->_pPre = prev;
            newNode->_pNext = cur;
            cur->_pPre = newNode;
            Lsize++;
            return newNode;
        }

        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            assert(pos != end());
            Node* del = pos._pNode;
            Node* prev = del->_pPre;
            Node* next = del->_pNext;
            delete del;
            prev->_pNext = next;
            next->_pPre = prev;
            --Lsize;
            return next;
        }
        void clear()
        {
            iterator it = begin();
            while (it != end())
            {
                it = erase(it);
            }
            Lsize = 0;
        }

        void swap(list<T>& l)
        {
            std::swap(_pHead, l._pHead);
            std::swap(Lsize, l.Lsize);
        }
    private:
        PNode _pHead;
        size_t Lsize = 0;
    };












}