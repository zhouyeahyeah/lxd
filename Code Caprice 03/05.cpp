//四数相加II
/*给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
为了使问题简单化，所有的 A, B, C, D 具有相同的⻓度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1
之间，最终结果不会超过 2^31 - 1 。*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map; // key:a+b的数值，value:a+b数值出现的次数
        for(int a:A)
        {
            for(int b:B)
            {
                map[a+b]++;
            }
        }
        int count=0;
        for(int c:C)
        {
            for(int d:D)
            {
                if(map.find(0-(c+d))!=map.end())
                {
                    count += map[0-(c+d)];
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    // Test Case
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};

    int result = solution.fourSumCount(A, B, C, D);

    cout << "Test Case:" << endl;
    cout << "A: [1, 2]" << endl;
    cout << "B: [-2, -1]" << endl;
    cout << "C: [-1, 2]" << endl;
    cout << "D: [0, 2]" << endl;
    cout << "Result: " << result << endl;

    system("pause");
    return 0;
}