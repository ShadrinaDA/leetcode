class Solution {
public:
    int maxDepth(string s) {
        int max = 0;
        int cur = 0;
        for (char c:s) {
            if (cur >= max) {
                max = cur;
            }
            if (c=='(') {
                ++cur;
            }
            if (c == ')') {
                --cur;
            }
        }
        return max;
    }
};