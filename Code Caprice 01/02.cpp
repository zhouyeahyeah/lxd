/**给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。*/

#include<iostream>
#include<vector>
using  namespace std;

class Solution
{
public:
        int search(vector<int> &nums,int target)
        {
            int left=0;
            int right=nums.size()-1;
            while(left<=right)
            {
                int middle=(left+right)/2;
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
            return right+1;
        }
};

class Solution02
{
public:
        int search(vector<int> &nums,int target)
        {
            int left=0;
            int right=nums.size();
            while(left<right)
            {
                int middle=(left+right)/2;
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
            return right;
        }
};



int main()
{
    vector<int> nums={1,3,5,6,10,14,19,26};
    int target=27;
    Solution02 s;
    int abc=s.search(nums,target);
    cout<<abc<<endl;
    system("pause");
    return 0;
}