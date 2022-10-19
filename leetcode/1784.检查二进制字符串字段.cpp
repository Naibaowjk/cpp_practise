/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 *
 * https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/
 *
 * algorithms
 * Easy (42.91%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    27.4K
 * Total Submissions: 49K
 * Testcase Example:  '"1001"'
 *
 * 给你一个二进制字符串 s ，该字符串 不含前导零 。
 * 
 * 如果 s 包含 零个或一个由连续的 '1' 组成的字段 ，返回 true​​​ 。否则，返回 false 。
 * 
 * 如果 s 中 由连续若干个 '1' 组成的字段 数量不超过 1，返回 true​​​ 。否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "1001"
 * 输出：false
 * 解释：由连续若干个 '1' 组成的字段数量为 2，返回 false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "110"
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 100
 * s[i]​​​​ 为 '0' 或 '1'
 * s[0] 为 '1'
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s) {
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            if (i<len-1 && s[i+1] == '1') s[i] = '0'; 
        }
        int num = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '1') num++;
        }
        return num<2;
    }
};
// @lc code=end

int main()
{
    return 0;
}