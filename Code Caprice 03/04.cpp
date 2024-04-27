//两数之和
//给定⼀个整数数组 nums 和⼀个⽬标值 target，请你在该数组中找出和为⽬标值的那 两个 整数，并返回他们的数组下标。你可以假设每种输⼊只会对应⼀个答案。但是，数组中同⼀个元素不能使⽤两遍。


#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();++i)
        {
            auto it = map.find(target-nums[i]);
            if(it != map.end())
            {
                return {min(i, it->second), max(i, it->second)};
            }
            else{
                map.insert({nums[i],i});
            }
        }
        return {};
    }
};


int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test Case 1:" << endl;
    cout << "Target: " << target1 << endl;
    cout << "Array: [2, 7, 11, 15]" << endl;
    cout << "Result: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // Test Case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "\nTest Case 2:" << endl;
    cout << "Target: " << target2 << endl;
    cout << "Array: [3, 2, 4]" << endl;
    cout << "Result: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // Test Case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "\nTest Case 3:" << endl;
    cout << "Target: " << target3 << endl;
    cout << "Array: [3, 3]" << endl;
    cout << "Result: [" << result3[0] << ", " << result3[1] << "]" << endl;


    system("pause");
    return 0;
}
