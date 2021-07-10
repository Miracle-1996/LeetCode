class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> s(n + 1, 0);
        partial_sum(nums.begin(), nums.end(), s.begin() + 1);
        int res = 0; map<int, int> hash;
        for (int r = 0; r <= n; ++r) {
            res += hash[s[r] - k]; hash[s[r]]++; 
        }
        return res;
    }
};
// type: partial-sum + hash

/* tips */
/*
    s[r] - s[l - 1] == k
    s[r] = s[l - 1] + k
*/

/* editorial */
/*
*/

/* question */
/*
    hash.count(s[r] - k) vs hash[s[r] - k]
*/