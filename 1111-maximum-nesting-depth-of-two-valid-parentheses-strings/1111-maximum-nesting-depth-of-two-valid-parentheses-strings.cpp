class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int c = 0;
        for (char el : seq) {
            if (el == '(') {
                res.push_back(c%2);
                ++c;
            }
            else {
                --c;
                res.push_back(c%2);
            }
        }
        return res;
    }
};