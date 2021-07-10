class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = (int)nums.size();
        vector<int> s(n + 1, 0);
        partial_sum(nums.begin(), nums.end(), s.begin() + 1);
        int res = 0; map<int, int> hash;
        for (int r = 0; r <= n; ++r) {
            res += hash[s[r] - goal]; hash[s[r]]++;
        }
        return res;
    }
};
// type: partial-sum + hash

/* tips */
/*
    s[r] - s[l - 1] = goal
    s[l - 1] = s[r] - goal
*/

/* editorial */
/*
    注意负数取模 (s[r] % k + k) % k;
*/

/* question */
/*
*/