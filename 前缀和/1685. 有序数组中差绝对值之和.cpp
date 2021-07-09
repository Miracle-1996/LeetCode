class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n);
        vector<int> res(n, 0);
        // sum[0] = nums[0];
        // for (int k = 1; k < n; ++k) sum[k] = sum[k - 1] + nums[k];
        partial_sum(nums.begin(), nums.end(), sum.begin());
        for (int k = 0; k < n; ++k) {
            if (k >= 1)     res[k] += k * nums[k] - sum[k - 1];
            if (k <= n - 2) res[k] += sum[n - 1] - sum[k] - (n - k - 1) * nums[k];
        }
        return res;
    }
};

// type: partial-sum

/* tips */
/*
    res[k] += k * sum[k] - sum[k - 1] (k >= 1)
    res[k] += sum[n - 1] - sum[k] - (n - k - 1) * nums[k]; (k <= n - 2)
*/

/* editorial */
/*
*/

/* question */
/*
*/