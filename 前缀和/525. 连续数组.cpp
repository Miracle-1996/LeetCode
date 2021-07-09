class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> sum(n + 1, 0);
        partial_sum(nums.begin(), nums.end(), sum.begin() + 1);
        vector<int> v(n + 1, 0);
        for (int k = 0; k <= n; ++k) v[k] = 2 * sum[k] - k;
        int res = 0; 
        map<int, int> hash;
        for (int k = 0; k <= n; ++k) {
            (hash.count(v[k])) ? res = max(res, k - hash[v[k]]) : hash[v[k]] = k;
            // (hash.find(v[k]) != hash.end()) ? res = max(res, k - hash[v[k]]) : hash[v[k]] = k;
        }
        return res;
    }
};
// type: partial-sum + hash 

/* tips */
/*
    2 * s[r] - 2 * s[l - 1] = r - (l - 1)
    2 * s[r] - r = 2 * s[l - 1] - (l - 1)
    b[k] = 2 * s[k] - k (0 <= k <= n)
    (hash.count(v[k])) ? res = max(res, k - hash[v[k]]) : hash[v[k]] = k; 
    (hash.find(v[k]) != hash.end()) ? res = max(res, k - hash[v[k]]) : hash[v[k]] = k;
*/

/* editorial */
/*
*/

/* question */
/*
    hash.find(v[k]) != hash.end() vs hash[v[k]] ? 
*/