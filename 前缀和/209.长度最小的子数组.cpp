class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = (int)nums.size();
        vector<int64_t> s(size + 1, 0);
        for (int k = 1; k <= size; ++k) s[k] = s[k - 1] + nums[k - 1];
        int l = 1, r = 1, res = size + 1;
        for (; l <= size; ++l) {
            while (r < size && s[r] < s[l - 1] + target) ++r;
            if (s[r] >= s[l - 1] + target) res = min(res, r - l + 1); 
        }
        return (res == size + 1) ? 0 : res;
    }
};
// type: partial-sum + two-pointers / binary_search

/* tips */
/*
    sum[r] - sum[l - 1] >= target
*/

/* editorial */
/*
*/

/* question */
/*
*/