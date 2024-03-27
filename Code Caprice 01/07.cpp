/*
螺旋矩阵II
给定⼀个正整数 n，⽣成⼀个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正⽅形矩阵。
示例:
输⼊: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include<iostream>
#include<vector>
using namespace std;



class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0)); // 使⽤vector定义⼀个⼆维数组
    int startx = 0, starty = 0; // 定义每循环⼀个圈的起始位置
    int loop = n / 2; // 每个圈循环⼏次，例如n为奇数3，那么loop = 1 只是循环⼀圈，矩阵中间的值需要单独处理
    int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
    int count = 1; // ⽤来给矩阵中每⼀个空格赋值
    int offset = 1; // 需要控制每⼀条边遍历的⻓度，每次循环右边界收缩⼀位
    int i,j;
    while (loop --) 
    {
        i = startx;
        j = starty;
        // 下⾯开始的四个for就是模拟转了⼀圈
        // 模拟填充上⾏从左到右(左闭右开)
        for (j = starty; j < n - offset; j++) 
        {
            res[startx][j] = count++;
        }
        // 模拟填充右列从上到下(左闭右开)
        for (i = startx; i < n - offset; i++) 
        {
            res[i][j] = count++;
        }
        // 模拟填充下⾏从右到左(左闭右开)
        for (; j > starty; j--) 
        {
            res[i][j] = count++;
        }
        // 模拟填充左列从下到上(左闭右开)
        for (; i > startx; i--) 
        {
            res[i][j] = count++;
        }
        // 第⼆圈开始的时候，起始位置要各⾃加1， 例如：第⼀圈起始位置是(0, 0)，第⼆圈起始位置是(1, 1)
        startx++;
        starty++;
        // offset 控制每⼀圈⾥每⼀条边遍历的⻓度
        offset += 1;
    }
    // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
    if (n % 2) 
    {
        res[mid][mid] = count;
    }
    return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> abc=s.generateMatrix(6);
    // 遍历每一行
    for (const vector<int>& row : abc) 
    {
        // 遍历当前行的每个元素
        for (int num : row) {
            // 使用 cout 输出当前元素
            cout << num << " ";
        }
        // 换行显示下一行
        cout << std::endl;
    }
    system("pause");
    return 0;
}