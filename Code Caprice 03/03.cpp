//编写⼀个算法来判断⼀个数 n 是不是快乐数。
//「快乐数」定义为：对于⼀个正整数，每⼀次将该数替换为它每个位置上的数字的平⽅和，然后重复这个过程直到这个数变为 1，也可能是 ⽆限循环 但始终变不到 1。如果 可以变为 1，那么这个数就是快乐数。

#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //取数值各个位上的单数之和
    int getSum(int n)
    {
        int sum=0;
        while(n)
        {
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> set;
        while(1)
        {
            int sum = getSum(n);
            if(sum == 1)
            {
                return true;
            }
            if(set.find(sum)!=set.end())
            {
                return false;
            }
            else{
                set.insert(sum);
            }
            n = sum;
        }
    }
};

int main() {
    Solution solution;
    
    // 测试例子1
    int number1 = 19;
    cout << number1 << (solution.isHappy(number1) ? " is " : " not is ") << "happy" << endl;

    // 测试例子2
    int number2 = 7;
    cout << number2 << (solution.isHappy(number2) ? " is " : " not is ") << "happy" << endl;

    // 测试例子3
    int number3 = 123;
    cout << number3 << (solution.isHappy(number3) ? " is " : " not is ") << "happy" << endl;

    system("pause");
    return 0;
}
