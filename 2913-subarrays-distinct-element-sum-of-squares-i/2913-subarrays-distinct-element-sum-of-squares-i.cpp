class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int summa = 0;
        for (int i = 0; i < nums.size(); ++i) {
            set<int> ns;
            for (int j = i; j < nums.size(); ++j) {
                ns.insert(nums[j]*nums[j]);
                summa += ns.size()*ns.size();
            }
        }
        return summa;
    }
};