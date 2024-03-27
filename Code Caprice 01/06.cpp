/*⻓度最⼩的⼦数组   
给定⼀个含有 n 个正整数的数组和⼀个正整数 s ，找出该数组中满⾜其和 ≥ s 的⻓度最⼩的 连续 ⼦数组，并返回
其⻓度。如果不存在符合条件的⼦数组，返回 0。
示例：
输⼊：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：⼦数组 [4,3] 是该条件下的⻓度最⼩的⼦数组。*/

#include<iostream>
#include<vector>
using namespace std;

//后⾯⼒扣更新了数据，暴⼒解法已经超时了
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int result = INT32_MAX; // 最终的结果
        int sum = 0; // ⼦序列的数值之和
        int subLength = 0; // ⼦序列的⻓度
        for (int i = 0; i < nums.size(); i++) 
        {   
            // 设置⼦序列起点为i
            sum = 0;
            for (int j = i; j < nums.size(); j++) 
            {   
                // 设置⼦序列终⽌位置为j
                sum += nums[j];
                if (sum >= s) 
                {   
                    // ⼀旦发现⼦序列和超过了s，更新result
                    subLength = j - i + 1; // 取⼦序列的⻓度
                    result = result < subLength ? result : subLength;
                    break; // 因为我们是找符合条件最短的⼦序列，所以⼀旦符合条件就break
                }
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的⼦序列
        return result == INT32_MAX ? 0 : result;
        }
};

//滑动窗口方法
//！！！！！！！！！！！！！！！！
//滑动窗⼝的精妙之处在于根据当前⼦序列和⼤⼩的情况，不断调节⼦序列的起始位置。从⽽将O(n^2)暴⼒解法降为O(n)

class Solution01 {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int result = INT32_MAX; // 最终的结果
        int i=0;
        int sum = 0; // ⼦序列的数值之和
        int subLength = 0; // ⼦序列的⻓度
        for (int j = 0; j < nums.size(); j++) 
        {   
            sum += nums[j];
            while(sum>=s)
            {
                subLength=j-i+1;
                result=result<subLength?result:subLength;
                sum -= nums[i];
                i++;
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的⼦序列
        return result == INT32_MAX ? 0 : result;
        }
};


int main()
{
    vector<int> nums={2,3,1,2,4,3};
    int s=7;
    Solution01 s1;
    int abc=s1.minSubArrayLen(s,nums);
    cout<<abc<<endl;
    system("pause");
    return 0;
}