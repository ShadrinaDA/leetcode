class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res="";
        int summm = sum;
        if (sum <= 0 || sum > 9 * num) {
            return "";
        }
        while (num>0) {
            if (sum <= 0) {
                res+="0";
            }
            else if (sum<10) {
                res += to_string(sum);
            }
            else {
                res += "9";
            }
            sum -=9;
            --num;
        }
        return res;
    }
};