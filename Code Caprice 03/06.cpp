//赎⾦信
/*给定⼀个赎⾦信 (ransom) 字符串和⼀个杂志(magazine)字符串，判断第⼀个字符串 ransom 能不能由第⼆个字符
串 magazines ⾥⾯的字符构成。如果可以构成，返回 true ；否则返回 false。
(题⽬说明：为了不暴露赎⾦信字迹，要从杂志上搜索各个需要的字⺟，组成单词来表达意思。杂志字符串中的每个
字符只能在赎⾦信字符串中使⽤⼀次。)*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int record[26] = {0};
        //add
        if (ransomNote.size() > magazine.size()) 
        {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) 
        {
            // 通过record数据记录 magazine⾥各个字符出现次数
            record[magazine[i]-'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) 
        {
            // 遍历ransomNote，在record⾥对应的字符个数做--操作
            record[ransomNote[j]-'a']--;
            // 如果⼩于零说明ransomNote⾥出现的字符，magazine没有
            if(record[ransomNote[j]-'a'] < 0) 
            {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string ransomNote = "ransom";
    string magazine = "this is a magazine containing the ransom note";
    
    if (sol.canConstruct(ransomNote, magazine)) {
        cout << "The ransom note can be constructed from the magazine." << endl;
    } else {
        cout << "The ransom note cannot be constructed from the magazine." << endl;
    }
    
    system("pause");
    return 0;
}