#include "list.h"
#include <iostream>
using namespace std;

void Print(const lwd::list<int>& l)
{
    for (auto& e : l)
    {
        cout << e << " ";

    }
    cout << endl;
}

//测试List的构造、insert、push_back函数和迭代器
void test1()
{
    lwd::list<int> It;
    It.push_back(0);
    It.push_back(23);
    It.push_back(10);
    It.push_back(4);
    It.insert(It.begin(),52);
        
    Print(It);
}

//测试clear、erase、析构、pop_front、push_front、用list对象给list初始化的构造函数
 //和用n个变量给List初始化
void test2()
{
    lwd::list<int> It;
    It.push_back(0);
    It.push_back(23);
    It.push_back(10);
    It.push_back(4);
    Print(It);
    It.clear();
    It.push_back(4);
    It.push_back(5);
    It.push_back(6);
    It.push_front(7);
    Print(It);
    It.pop_front();
    Print(It);
    lwd::list<int> It1(It);
    Print(It1);
    lwd::list<int> It2(10, 520);
    Print(It2);
}

int main()
{
    test1();
    cout<<".............."<<endl;
    test2();
    system("pause");
    return 0;
}