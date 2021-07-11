class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = (int)nums.size();
        vector<int> s(n + 1, 0);
        partial_sum(nums.begin(), nums.end(), s.begin() + 1);
        int sum = s[n];
        int res = 0; 
        unordered_map<int, int> hash;
        for (int r = 0; r <= n; ++r) {
            int val = s[r] + x - sum;
            if (hash.count(val)) res = max(res, r - hash[val]);
            hash[s[r]] = r;
        }
        // int l = 1, r = 1;
        // for (; l <= n; ++l) {
        //     while (r < n && s[r] < s[l - 1] - x + sum) ++r;
        //     if (s[r] == s[l - 1] - x + sum) res = max(res, r - l + 1);
        // }
        return (sum == x) ? n : (0 == res) ? -1 : n - res;
    }
};
// type: partial-sum + hash / two-pointers / binary_search

/* tips */
/*
    s[r] - s[l - 1] = sum - x;
*/

/* editorial */
/*
*/

/* question */
/*
*/