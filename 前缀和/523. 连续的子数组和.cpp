class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> s(n + 1, 0);
        partial_sum(nums.begin(), nums.end(), s.begin() + 1);
        map<int, int> hash;
        for (int i = 0; i <= n; ++i) {
            int x = s[i] % k;
            if (hash.count(x) != 0)  {
                if (i - hash[x] >= 2) return true;
            }
            else hash[x] = i; 
        }
        return false;
    }
};