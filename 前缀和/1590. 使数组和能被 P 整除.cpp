class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = (int)nums.size();
        vector<int64_t> s(n + 1, 0);
        for (int k = 1; k <= n; ++k) s[k] = s[k - 1] + nums[k - 1];
        unordered_map<int, int> hash;
        int64_t x = accumulate(nums.begin(), nums.end(), 0ll);
        int res = (x % p) ? n : 0; 
        for (int r = 0; r <= n; ++r) {
            if (hash.count(s[r] % p)) res = min(res, r - hash[s[r] % p]);
            hash[(s[r] + x) % p] = r; 
        }
        return (res < n) ? res : -1;
    }
};
// type: partial-sum + hash

/* tips */
/*
    sum - (s[r] - s[l - 1]) = np
    sum + s[l - 1] - s[r] = np
    s[l - 1] + sum ≡ s[r] (mod p)
*/

/* editorial */
/*
*/

/* question */
/*
*/