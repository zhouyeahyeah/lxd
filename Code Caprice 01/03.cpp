/** 给你⼀个数组 nums 和⼀个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新⻓度。
不要使⽤额外的数组空间，你必须仅使⽤ O(1) 额外空间并原地修改输⼊数组。

元素的顺序可以改变。你不需要考虑数组中超出新⻓度后⾯的元素。
示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的⻓度 2, 并且 nums 中的前两个元素均为 2。
你不需要考虑数组中超出新⻓度后⾯的元素。
示例 2:
给定 nums = [0,1,2,2,3,0,4,2], val = 2,
函数应该返回新的⻓度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。*/

//快慢指针方法

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int slowIndex = 0;
        for(int fastIndex=0;fastIndex<nums.size();fastIndex++)
        {
            if(val != nums[fastIndex])
            {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};


/**
* 相向双指针⽅法，基于元素顺序可以改变的题⽬描述改变了元素相对位置，确保了移动最少元素
* 时间复杂度：O(n)
* 空间复杂度：O(1)
*/
class Solution01
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int leftIndex=0;
        int rightIndex=nums.size()-1;
        while(leftIndex<=rightIndex)
        {   
            // 找左边等于val的元素
            while(leftIndex<=rightIndex&&nums[leftIndex] != val){
                leftIndex++;
            }
            // 找右边不等于val的元素
            while(leftIndex<=rightIndex&&nums[rightIndex] == val){
                rightIndex--;
            }
            // 将右边不等于val的元素覆盖左边等于val的元素
            if(leftIndex<rightIndex){
                nums[leftIndex]=nums[rightIndex];
                leftIndex++;
                rightIndex--;
            }
        }
        return leftIndex;
    }
};


int main()
{
    vector<int> nums={0,1,2,2,3,0,4,2};
    int val=2;
    Solution01 s1;
    int abc = s1.removeElement(nums,val);
    cout<<abc<<endl;
    system("pause");
    return 0;
}

