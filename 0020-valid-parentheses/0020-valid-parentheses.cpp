class Solution {
public:
    bool isValid(string str) {
        vector<char> sym;
        for (char s : str) {
            if (s == ')') {
                if (sym.empty() == false &&  sym.back() == '(') {
                    sym.pop_back();
                } 
                else {
                    return false;
                }
            }
            else if (s == '}') {
                if (sym.empty() == false &&  sym.back() == '{') {
                    sym.pop_back();
                } 
                else {
                    return false;
                }
            }
            else if (s == ']') {
                if (sym.empty() == false &&  sym.back() == '[') {
                    sym.pop_back();
                } 
                else {
                    return false;
                }
            }
            else {
                sym.push_back(s);
            }
        }
        if (sym.empty()) {
            return true;
        }
        return false;
    }
};