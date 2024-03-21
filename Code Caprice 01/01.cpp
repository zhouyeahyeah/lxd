//二分查找

/*给定⼀个 n 个元素有序的（升序）整型数组 nums 和⼀个⽬标值 target ，写⼀个函数搜索 nums 中的 target，如
果⽬标值存在返回下标，否则返回 -1。*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int abc;
    vector<int>::iterator it = find(nums.begin(),nums.end(),target);
    if(it != nums.end())
    {
        //abc = distance(it,nums.begin());  颠倒后就是-4
        abc = distance(nums.begin(),it);
        cout<<abc<<endl;
    }
    else
    {
        abc = -1;
        cout<<abc<<endl;
    }
    system("pause");
    return 0;
}


