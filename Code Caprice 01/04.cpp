//给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。元素的相对顺序应该保持 一致 。然后返回 nums 中唯一元素的个数。


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        while(i<nums.size()-1)
        {
            if(nums[i]==nums[i+1])
            {
                for(int j=i;j<nums.size()-1;j++)
                {
                    nums[j]=nums[j+1];
                }
                nums.pop_back();
                i=0;
            }
            else{
                i++;
            }

        }
        return nums.size() ;
    }
};

int main()
{
    vector<int> nums={1,1,1};
    Solution s;
    int abc=s.removeDuplicates(nums);
    cout<<abc<<endl;
    system("pause");
    return 0;
}