class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int sc = 0;
        for (char c:s) {
            if (c == '(') {
                ++sc;
            }
            else {
                --sc;
                if (sc < 0) {
                    ++count;
                    sc = 0;
                }
            }
        }
        count += sc;
        return count;
    }
};