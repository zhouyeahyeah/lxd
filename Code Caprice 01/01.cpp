//二分查找

/*给定⼀个 n 个元素有序的（升序）整型数组 nums 和⼀个⽬标值 target ，写⼀个函数搜索 nums 中的 target，如
果⽬标值存在返回下标，否则返回 -1。*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// int main()
// {
//     vector<int> nums = {-1,0,3,5,9,12};
//     int target = 9;
//     int abc;
//     vector<int>::iterator it = find(nums.begin(),nums.end(),target);
//     if(it != nums.end())
//     {
//         //abc = distance(it,nums.begin());  颠倒后就是-4
//         abc = distance(nums.begin(),it);
//         cout<<abc<<endl;
//     }
//     else
//     {
//         abc = -1;
//         cout<<abc<<endl;
//     }
//     system("pause");
//     return 0;
// }


/**⼆分法第⼀种写法
第⼀种写法，我们定义 target 是在⼀个在左闭右闭的区间⾥，也就是[left, right] （这个很重要⾮常重要）。
区间的定义这就决定了⼆分法的代码应该如何写，因为定义target在[left, right]区间，所以有如下两点：
while (left <= right) 要使⽤ <= ，因为left == right是有意义的，所以使⽤ <=
if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]⼀定不是target*/

class solution01
{
public:
    int search(vector<int> &nums,int &target)
    {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int middle = left+((right-left)/2);   //防止溢出
            if(nums[middle]>target)
            {
                right=middle-1;
            }
            else if(nums[middle]<target)
            {
                left=middle+1;
            }
            else{
                return middle;
            }
        }
        //未找到目标值
        return -1;
    }
};


/**⼆分法第⼆种写法
如果说定义 target 是在⼀个在左闭右开的区间⾥，也就是[left, right) ，那么⼆分法的边界处理⽅式则截然不同。
有如下两点：
while (left < right)，这⾥使⽤ < ,因为left == right在区间[left, right)是没有意义的
if (nums[middle] > target) right 更新为 middle，因为当前nums[middle]不等于target，去左区间继续寻
找，⽽寻找区间是左闭右开区间，所以right更新为middle，即：下⼀个查询区间不会去⽐较nums[middle]*/

class solution02
{
public:
    int search(vector<int> &nums,int &target)
    {
        int left = 0;
        int right = nums.size();
        while(left<right)
        {
            int middle = left+((right-left)/2);   //防止溢出
            if(nums[middle]>target)
            {
                right=middle;
            }
            else if(nums[middle]<target)
            {
                left=middle+1;
            }
            else{
                return middle;
            }
        }
        //未找到目标值
        return -1;
    }
};


int main()
{
    //solution01 s1;
    solution02 s1;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int result = s1.search(nums,target);
    cout<<result<<endl;
    system("pause");
    return 0;
}

