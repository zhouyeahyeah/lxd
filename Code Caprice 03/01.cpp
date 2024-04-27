// 有效的字⺟异位词
// 给定两个字符串 s 和 t ，编写⼀个函数来判断 t 是否是 s 的字⺟异位词

#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t) {
        int record[26]={0};
        for(int i=0;i<s.size();i++)
        {
            // 并不需要记住字符a的ASCII，只要求出⼀个相对数值就可以了
            record[s[i]-'a']++;
        }

        for(int i=0;i<t.size();i++)
        {
            record[t[i]-'a']--;
        }

        for(int i=0;i<26;i++)
        {
            if(record[i]!=0)
            {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    bool result = solution.isAnagram(s, t);
    if (result) {
        cout << "s and t are valid alphabets" << endl;
    } else {
        cout << "s and t are not valid alphabets" << endl;
    }
    system("pause");
    return 0;
}

