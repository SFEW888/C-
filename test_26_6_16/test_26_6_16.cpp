#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>

//int main()
//{
//    std::string s1 = "Test";
//    //  std::string&& r1 = s1;           // 错误：不能绑定到左值 
//    const std::string& r2 = s1 + s1;     // OK：到 const 的左值引用延⻓生存期 
//    //  r2 += "Test";                    // 错误：不能通过到 const 的引用修改 
//    std::string&& r3 = s1 + s1;          // OK：右值引用延⻓生存期 
//    r3 += "Test";                        // OK：能通过到非 const 的引用修改 
//    std::cout << r3 << '\n';
//    return 0;
//}



#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 传值返回需要拷⻉ 
    string addStrings(string num1, string num2) {
        string str;
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        // 进位 
        int next = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
            int ret = val1 + val2 + next;
            next = ret / 10;
            ret = ret % 10;
            str += ('0' + ret);
        }
        if (next == 1)
            str += '1';
        reverse(str.begin(), str.end());
        return str;
    }
};
class Solution {
public:
    // 这里的传值返回拷⻉代价就太大了 
    /*vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            vv[i].resize(i + 1, 1);
        }
        for (int i = 2; i < numRows; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
            }
        }
        return vv;
    }*/

    //应该这样改
    void generate(int numRows, vector<vector<int>> vv) {
        vector<vector<int>> vv(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            vv[i].resize(i + 1, 1);
        }
        for (int i = 2; i < numRows; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
            }
        }
    }
};

int main()
{
    vector<vector<int>> ret;
    Solution().generate(100, ret);
}

