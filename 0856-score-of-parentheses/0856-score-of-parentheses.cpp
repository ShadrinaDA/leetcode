class Solution {
public:
    int scoreOfParentheses(string s) {
        int count = 0, total = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ')' && s[i-1] !='(') {
                --count;
            }
            else if (s[i] == ')') {
                --count;
                total +=1<<count;
            }
            else {
                ++count;
            }
        }
        return total;
    }
};