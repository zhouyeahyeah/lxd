// 两个数组的交集
// 给定两个数组，编写⼀个函数来计算它们的交集
// 输出结果中的每个元素⼀定是唯⼀的

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(auto nums:nums2)
        {
            if(find(nums_set.begin(),nums_set.end(),nums)!=nums_set.end())
            {
                result_set.insert(nums);
            }
        }
        vector<int> result(result_set.begin(),result_set.end());
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    vector<int> result = solution.intersection(nums1, nums2);
    
    cout << "The intersection result is:";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    system("pause");
    return 0;
}
