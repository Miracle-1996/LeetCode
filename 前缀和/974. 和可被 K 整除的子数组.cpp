class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> s(n + 1, 0);
        partial_sum(nums.begin(), nums.end(), s.begin() + 1);
        int res = 0; map<int, int> hash;
        for (int r = 0; r <= n; ++r) {
            int x = (s[r] % k + k) % k;
            res += hash[x]; hash[x]++;
        }
        return res;
    }
};
// type: partial-sum + hash

/* tips */
/*
    s[r] - s[l - 1] = n * k
    s[r] ≡ s[l - 1] (mod k)
*/

/* editorial */
/*
    注意负数取模 (s[r] % k + k) % k;
*/

/* question */
/*
*/