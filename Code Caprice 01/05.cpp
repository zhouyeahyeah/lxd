/*比较含退格的字符串  给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        while(s[0]=='#')
        {
            s=s.substr(1);
        }
        while(t[0]=='#')
        {
            t=t.substr(1);
        }
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='#')
            {   
                if (i - 1 >= 0) {
                    s = s.erase(i - 1, 2);
                    i = 0;
                }
                else{
                    s=s.erase(i,1);
                    i=0;
                }
            }
            else{
                i++;
            }
        }
        int j=0;
        while(j<t.size())
        {
            if(t[j]=='#')
            {
                if (j - 1 >= 0) {
                    t = t.erase(j - 1, 2);
                    j = 0;
                }
                else{
                    t=t.erase(j,1);
                    j=0;
                }
            }
            else{
                j++;
            }
        }
        if(s==t)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};

int main()
{
    string s = "ab#c";
    string t = "ad#c";
    Solution s1;
    bool abc=s1.backspaceCompare(s,t);
    cout<<abc<<endl;
    system("pause");
    return 0;
}