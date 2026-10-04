class Solution {
public:
    bool checkValidString(string s) {
        vector<int> sc;
        vector<int> stars;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                stars.push_back(i);
            }
            if (s[i] == '(') {
                sc.push_back(i);
            }
            if (s[i] == ')') {
                if (sc.empty() == false) {
                    sc.pop_back();
                }
                else if (stars.empty() == false) {
                    stars.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        if (sc.empty() == false) {
            for (int i = 0; i < sc.size(); ++i) {
                bool fl = false;
                for (int j = 0; j < stars.size(); ++j) {
                    if (sc[i] < stars[j] && fl == false) {
                        stars.erase(stars.begin() + j);
                        fl = true;
                    }
                }
                if(fl == false) {
                    return false;
                }
            }
        }
        return true;
    }
};