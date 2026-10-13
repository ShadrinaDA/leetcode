class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int minus = nums.size() - ceil(nums.size()/2.0);
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return std::abs(a) < std::abs(b);
        });
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < minus) {
                res -= nums[i]*nums[i];
            }
            else{
                res += nums[i]*nums[i];
            }
        }
        return res;
    }
};